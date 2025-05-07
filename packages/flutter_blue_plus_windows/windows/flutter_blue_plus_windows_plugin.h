#ifndef FLUTTER_PLUGIN_FLUTTER_BLUE_PLUS_WINDOWS_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTER_BLUE_PLUS_WINDOWS_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Devices.Bluetooth.h>
#include <winrt/Windows.Devices.Enumeration.h>
#include <winrt/Windows.Foundation.Collections.h>

#include <memory>
#include <coroutine>

namespace flutter_blue_plus_windows {

using namespace winrt;
using namespace winrt::Windows;
using namespace winrt::Windows::Devices;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Storage::Streams;
using namespace winrt::Windows::Devices::Radios;
using namespace winrt::Windows::Devices::Bluetooth;
using namespace winrt::Windows::Devices::Bluetooth::Advertisement;
using namespace winrt::Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace Windows::Devices::Enumeration;

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
