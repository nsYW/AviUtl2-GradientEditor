#include "menu_bar.h"

#include "imgui.h"
#include "utils/aviutl2/config2_utils.h"

namespace gradient_editor {
void MenuBar::render(WindowVisible* window_visible)
{
    if (ImGui::BeginMenuBar()) {
        // メニューバー領域のホバー判定
        ImVec2 win_pos  = ImGui::GetWindowPos();
        ImVec2 win_size = ImGui::GetWindowSize();
        ImVec2 mp       = ImGui::GetIO().MousePos;

        float bar_h = ImGui::GetFrameHeight();

        bool menu_bar_hovered =
            mp.x >= win_pos.x &&
            mp.x < win_pos.x + win_size.x &&
            mp.y >= win_pos.y &&
            mp.y < win_pos.y + bar_h;

        if (menu_bar_hovered) {
            m_is_menubar_hovered = true;
        } else {
            m_is_menubar_hovered = false;
        }

        // 表示メニュー
        if (ImGui::BeginMenu(aul2::tr(L"表示").c_str())) {
            ImGui::MenuItem(aul2::tr(L"プリセット").c_str(), nullptr, &window_visible->preset_window);
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}
}  // namespace gradient_editor
