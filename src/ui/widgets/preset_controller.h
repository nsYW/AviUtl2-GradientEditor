#ifndef PRESET_CONTROLLER_H
#define PRESET_CONTROLLER_H

#include "gradient_data.h"
#include "gradient_preset.h"

namespace gradient_editor {

class PresetController {
public:
    static gradient_editor::GradientData preset2gradient(const preset::GradientPreset& preset);

    static preset::GradientPreset gradient2preset(gradient_editor::GradientData& gradient);

    static bool deletePreset(PresetManager& manager, preset_file::GradientPresetFile& file, const uint32_t index);

    static bool swapPreset(PresetManager& manager, preset_file::GradientPresetFile& file, const uint32_t index_1, const uint32_t index_2);

    static bool overwritePreset(PresetManager& manager, preset_file::GradientPresetFile& file, preset::GradientPreset preset, const std::string& new_name, const uint32_t index);

    static bool addPreset(PresetManager& manager, preset_file::GradientPresetFile& file, preset::GradientPreset preset, const std::string& new_name);
};

}  // namespace gradient_editor

#endif
