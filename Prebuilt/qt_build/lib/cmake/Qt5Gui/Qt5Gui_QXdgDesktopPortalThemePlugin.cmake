
add_library(Qt5::QXdgDesktopPortalThemePlugin MODULE IMPORTED)

_populate_Gui_plugin_properties(QXdgDesktopPortalThemePlugin RELEASE "platformthemes/libqxdgdesktopportal.so")

list(APPEND Qt5Gui_PLUGINS Qt5::QXdgDesktopPortalThemePlugin)
