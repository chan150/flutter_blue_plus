#include "include/flutter_blue_plus_windows/flutter_blue_plus_windows_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "flutter_blue_plus_windows_plugin.h"

void FlutterBluePlusWindowsPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  flutter_blue_plus_windows::FlutterBluePlusWindowsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
