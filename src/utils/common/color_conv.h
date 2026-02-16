#ifndef COLOR_CONV_H
#define COLOR_CONV_H

#include <cstdint>

namespace color_conv {
template <typename Vec4>
constexpr Vec4 u32Rgba2Vec4Rgba(const uint32_t rgba)
{
    float inv_255 = 1.0f / 255.0f;
    float r       = static_cast<float>((rgba >> 24) & 0xFF) * inv_255;
    float g       = static_cast<float>((rgba >> 16) & 0xFF) * inv_255;
    float b       = static_cast<float>((rgba >> 8) & 0xFF) * inv_255;
    float a       = static_cast<float>(rgba & 0xFF) * inv_255;
    return Vec4{r, g, b, a};
}

template <typename Vec4>
constexpr Vec4 u32Rgb2Vec4Rgba(const uint32_t rgb, const uint32_t a = 0xFF)
{
    float inv_255 = 1.0f / 255.0f;
    float r       = static_cast<float>((rgb >> 16) & 0xFF) * inv_255;
    float g       = static_cast<float>((rgb >> 8) & 0xFF) * inv_255;
    float b       = static_cast<float>(rgb & 0xFF) * inv_255;
    float a_f     = static_cast<float>(a & 0xFF) * inv_255;
    return Vec4{r, g, b, a_f};
}

template <typename Vec4>
constexpr uint32_t vec4Rgba2u32Rgba(const Vec4& rgba)
{
    uint32_t r = static_cast<uint32_t>(rgba.x * 255.0f + 0.5f) & 0xFF;
    uint32_t g = static_cast<uint32_t>(rgba.y * 255.0f + 0.5f) & 0xFF;
    uint32_t b = static_cast<uint32_t>(rgba.z * 255.0f + 0.5f) & 0xFF;
    uint32_t a = static_cast<uint32_t>(rgba.w * 255.0f + 0.5f) & 0xFF;
    return (r << 24) | (g << 16) | (b << 8) | a;
}

constexpr uint32_t u32Rgb2u32Rgba(const uint32_t rgb, const uint32_t a = 0xFF)
{
    return (rgb << 8) | (a & 0xFF);
}

constexpr uint32_t u32Bgr2u32Abgr(const uint32_t bgr, const uint32_t a = 0xFF)
{
    uint8_t b = (bgr >> 16) & 0xFF;
    uint8_t g = (bgr >> 8) & 0xFF;
    uint8_t r = bgr & 0xFF;
    return (a << 24) | (b << 16) | (g << 8) | r;
}

constexpr uint32_t u32Rgb2u32Bgr(const uint32_t rgb)
{
    uint8_t r = (rgb >> 16) & 0xFF;
    uint8_t g = (rgb >> 8) & 0xFF;
    uint8_t b = rgb & 0xFF;
    return (b << 16) | (g << 8) | r;
}

constexpr uint32_t u32Rgba2u32Abgr(const uint32_t rgba)
{
    uint8_t r = (rgba >> 24) & 0xFF;
    uint8_t g = (rgba >> 16) & 0xFF;
    uint8_t b = (rgba >> 8) & 0xFF;
    uint8_t a = rgba & 0xFF;
    return (a << 24) | (b << 16) | (g << 8) | r;
}

}  // namespace color_conv

#endif  // !COLOR_CONV_H
