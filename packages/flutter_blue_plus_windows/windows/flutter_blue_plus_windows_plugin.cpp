#include "flutter_blue_plus_windows_plugin.h"

#include <windows.h>
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>
#include <map>
#include <string>
#include <vector>

namespace flutter_blue_plus_windows {

// static
void FlutterBluePlusWindowsPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "flutter_blue_plus/methods",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<FlutterBluePlusWindowsPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

FlutterBluePlusWindowsPlugin::FlutterBluePlusWindowsPlugin() {}

FlutterBluePlusWindowsPlugin::~FlutterBluePlusWindowsPlugin() {}

void FlutterBluePlusWindowsPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  const std::string& method = method_call.method_name();

  if (method == "setLogLevel") {
  }

  if (method == "setOptions") {
  }

  if (method == "flutterRestart") {
  }

  if (method == "connectedCount") {
  }

  if (method == "isSupported") {
  }

  if (method == "getAdapterName") {
  }

  if (method == "getAdapterState") {
  }

  if (method == "turnOn") {
  }

  if (method == "turnOff") {
  }

  if (method == "startScan") {
  }

  if (method == "stopScan") {
  }

  if (method == "getSystemDevices") {
  }

  if (method == "connect") {
  }

  if (method == "disconnect") {
  }

  if (method == "discoverServices") {
  }

  result->NotImplemented();
}

}  // namespace flutter_blue_plus_windows
