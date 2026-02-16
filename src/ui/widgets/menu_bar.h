#ifndef MENU_BAR_H
#define MENU_BAR_H

namespace gradient_editor {

struct WindowVisible {
    bool preset_window = true;
};

class MenuBar {
public:
    static void render(WindowVisible* window_visible);
    static bool isMenuBarHovered() { return m_is_menubar_hovered; }

private:
    inline static bool m_is_menubar_hovered = false;
};

}  // namespace gradient_editor

#endif
