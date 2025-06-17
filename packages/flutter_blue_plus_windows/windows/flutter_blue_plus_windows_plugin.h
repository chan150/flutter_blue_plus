#ifndef FLUTTER_PLUGIN_FLUTTER_BLUE_PLUS_WINDOWS_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTER_BLUE_PLUS_WINDOWS_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace flutter_blue_plus_windows {

class FlutterBluePlusWindowsPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlutterBluePlusWindowsPlugin();

  virtual ~FlutterBluePlusWindowsPlugin();

  // Disallow copy and assign.
  FlutterBluePlusWindowsPlugin(const FlutterBluePlusWindowsPlugin&) = delete;
  FlutterBluePlusWindowsPlugin& operator=(const FlutterBluePlusWindowsPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace flutter_blue_plus_windows

#endif  // FLUTTER_PLUGIN_FLUTTER_BLUE_PLUS_WINDOWS_PLUGIN_H_
