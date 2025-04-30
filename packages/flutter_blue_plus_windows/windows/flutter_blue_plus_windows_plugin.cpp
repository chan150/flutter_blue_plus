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

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Devices.Bluetooth.h>
#include <winrt/Windows.Devices.Enumeration.h>

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

//fire_and_forget FlutterBluePlusWindowsPlugin::GetSystemDevices() {
//    auto selector = winrt::Windows::Devices::Bluetooth::BluetoothDevice::GetDeviceSelector();
//    auto deviceInfoCollection = winrt::Windows::Devices::Enumeration::DeviceInformation::FindAllAsync(selector);
//    result(deviceInfoCollection);
//}

void FlutterBluePlusWindowsPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  const auto& method = method_call.method_name();

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

  if (method == "startScan") {

  }

  if (method == "stopScan") {
  }

  if (method == "getSystemDevices") {
    try {
      flutter::EncodableMap response = {};
      flutter::EncodableList deviceList;

      flutter::EncodableMap deviceMap;
      deviceMap[flutter::EncodableValue("remote_id")] = flutter::EncodableValue("FF:FF:FF:FF:FF:FF");
      deviceMap[flutter::EncodableValue("platform_name")] = flutter::EncodableValue("NAME");
      deviceList.push_back(flutter::EncodableValue(deviceMap));
      
//      for (const auto& deviceInfo : deviceInfoCollection) {
//        try {
//          flutter::EncodableMap deviceMap;
//          deviceMap[flutter::EncodableValue("id")] = flutter::EncodableValue(winrt::to_string(deviceInfo.Id()));
//          deviceMap[flutter::EncodableValue("name")] = flutter::EncodableValue(winrt::to_string(deviceInfo.Name()));
//          deviceList.push_back(flutter::EncodableValue(deviceMap));
//        } catch (const winrt::hresult_error& e) {
//          OutputDebugStringW(L"Error processing device: ");
//          OutputDebugStringW(e.message().c_str());
//          OutputDebugStringW(L"\n");
//        }
//      }
      
      response[flutter::EncodableValue("devices")] = deviceList;
      result->Success(flutter::EncodableValue(response));
    } catch (const winrt::hresult_error& e) {
      result->Error("getSystemDevices", winrt::to_string(e.message()));
    } catch (const std::exception& e) {
      result->Error("getSystemDevices", e.what());
    }
    return;
  }

  if (method == "connect") {
  }

  if (method == "disconnect") {
  }

  if (method == "discoverServices") {
  }

  result->NotImplemented();
}

}
