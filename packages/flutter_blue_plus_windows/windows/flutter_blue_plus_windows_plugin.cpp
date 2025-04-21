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
enum LogLevel {
  LNONE = 0,
  LERROR = 1,
  LWARNING = 2,
  LINFO = 3,
  LDEBUG = 4,
  LVERBOSE = 5,
};

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
    result->Success(flutter::EncodableValue(true));
    return;
  }

  if (method == "setOptions") {
    result->Success(flutter::EncodableValue(true));
    return;
  }

  if (method == "flutterRestart") {
    result->Success(flutter::EncodableValue(true));
    return;
  }

  if (method == "connectedCount") {
    result->Success(flutter::EncodableValue(true));
    return;
  }

  if (method == "isSupported") {
  }

  if (method == "getAdapterName") {
  }

  if (method == "getAdapterState") {
    flutter::EncodableMap response = {
        {flutter::EncodableValue("adapter_state"), flutter::EncodableValue(0)}
    };
    result->Success(flutter::EncodableValue(response));
    return;
  }

  if (method == "turnOn") {
    result->Success(flutter::EncodableValue(true));
    return;
  }

  if (method == "turnOff") {
    result->Success(flutter::EncodableValue(true));
    return;
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
