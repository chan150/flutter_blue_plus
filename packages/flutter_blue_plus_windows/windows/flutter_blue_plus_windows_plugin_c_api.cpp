#include "include/flutter_blue_plus_windows/flutter_blue_plus_plugin.h"

#include <flutter/plugin_registrar_windows.h>

#include "flutter_blue_plus_windows_plugin.h"

void FlutterBluePlusPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  flutter_blue_plus_windows::FlutterBluePlusWindowsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
