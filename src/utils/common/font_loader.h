#ifndef FONT_LOADER_H
#define FONT_LOADER_H

// clang-format off
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
// clang-format off

#include <dwrite.h>
#include <wrl/client.h>

#include <iostream>
#include <string>
#include <vector>

#include "imgui.h"

#pragma comment(lib, "dwrite.lib")

using Microsoft::WRL::ComPtr;

// フォント名からフォントのデータを取得する関数
std::vector<unsigned char> getFontDataByName(const std::wstring& font_name)
{
    ComPtr<IDWriteFactory> factory;
    DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &factory);

    ComPtr<IDWriteFontCollection> collection;
    factory->GetSystemFontCollection(&collection);

    UINT32 index;
    BOOL exists;
    collection->FindFamilyName(font_name.c_str(), &index, &exists);

    if (!exists) return {};  // 見つからない場合

    ComPtr<IDWriteFontFamily> family;
    collection->GetFontFamily(index, &family);

    ComPtr<IDWriteFont> font;
    family->GetFirstMatchingFont(
        DWRITE_FONT_WEIGHT_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        DWRITE_FONT_STYLE_NORMAL,
        &font
    );

    ComPtr<IDWriteFontFace> font_face;
    font->CreateFontFace(&font_face);

    // フォントファイル情報の取得
    UINT32 number_of_files = 0;
    font_face->GetFiles(&number_of_files, nullptr);
    if (number_of_files == 0) return {};

    ComPtr<IDWriteFontFile> font_file;
    font_face->GetFiles(&number_of_files, &font_file);

    ComPtr<IDWriteFontFileLoader> loader;
    font_file->GetLoader(&loader);

    // ローカルファイル用ローダーか確認
    ComPtr<IDWriteLocalFontFileLoader> local_loader;
    if (FAILED(loader.As(&local_loader))) return {};

    const void* font_file_reference_key;
    UINT32 font_file_reference_key_size;
    font_file->GetReferenceKey(&font_file_reference_key, &font_file_reference_key_size);

    ComPtr<IDWriteFontFileStream> stream;
    loader->CreateStreamFromKey(
        font_file_reference_key,
        font_file_reference_key_size,
        &stream
    );

    UINT64 file_size;
    stream->GetFileSize(&file_size);

    // メモリへの読み込み
    std::vector<unsigned char> buffer(static_cast<size_t>(file_size));
    const void* fragment_start;
    void* context;
    stream->ReadFileFragment(&fragment_start, 0, file_size, &context);

    memcpy(buffer.data(), fragment_start, buffer.size());

    stream->ReleaseFileFragment(context);

    return buffer;
}

#endif  // !FONT_LOADER_H
