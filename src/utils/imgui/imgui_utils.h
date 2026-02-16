#ifndef IMGUI_UTILS_H
#define IMGUI_UTILS_H

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h"

namespace imgui_utils {
// 次に配置する要素の位置を指定する
// https://github.com/ocornut/imgui/discussions/3862#discussioncomment-422097
void alignForWidth(float width, float alignment = 0.5f);

// スピンコントロール
// https://github.com/ocornut/imgui/issues/2649#issue-464385323
bool spinScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step, const void* p_step_fast, const char* format, ImGuiInputTextFlags flags);
bool spinInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0);

// ボタントグル
bool pushToggleButton(const char* label, bool* v, const ImVec2& size = ImVec2(0, 0));

// アイコンフォトント用の正方形のボタン
bool squareIconButton(const std::string& icon, const std::string& label);
}  // namespace imgui_utils

#endif
