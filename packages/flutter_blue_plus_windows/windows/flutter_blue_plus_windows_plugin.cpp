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

fire_and_forget GetSystemDevicesAsync(std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
    try {
      auto selector = BluetoothDevice::GetDeviceSelector();
      DeviceInformationCollection deviceInfoCollection = co_await DeviceInformation::FindAllAsync(selector);

      flutter::EncodableMap response = {};
      flutter::EncodableList deviceList;

      for (auto&& deviceInfo : deviceInfoCollection) {
          std::cout<<"TEST"<<std::endl;
        try {
          flutter::EncodableMap deviceMap = {};

          // Get device properties
          auto properties = deviceInfo.Properties();
          bool isPaired = false;
          if (properties.HasKey(L"System.Devices.Aep.IsPaired")) {
            isPaired = winrt::unbox_value<bool>(properties.Lookup(L"System.Devices.Aep.IsPaired"));
          }

          // Get device name
          std::string name = winrt::to_string(deviceInfo.Name());
          if (name.empty() && properties.HasKey(L"System.Devices.Aep.DeviceAddress")) {
            name = winrt::to_string(winrt::unbox_value<winrt::hstring>(properties.Lookup(L"System.Devices.Aep.DeviceAddress")));
          }

          deviceMap[flutter::EncodableValue("remote_id")] = flutter::EncodableValue(winrt::to_string(deviceInfo.Id()));
          deviceMap[flutter::EncodableValue("platform_name")] = flutter::EncodableValue(name);
//          deviceMap[flutter::EncodableValue("remote_id")] = flutter::EncodableValue("FF:FF:FF:FF:FF:FF");
//          deviceMap[flutter::EncodableValue("platform_name")] = flutter::EncodableValue("name");
//
//          deviceList.push_back(flutter::EncodableValue(deviceMap));
        } catch (const winrt::hresult_error& e) {
          OutputDebugStringW(L"Error processing device: ");
          OutputDebugStringW(e.message().c_str());
          OutputDebugStringW(L"\n");
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
      }

      response[flutter::EncodableValue("devices")] = deviceList;
      result->Success(flutter::EncodableValue(response));
    } catch (const winrt::hresult_error& e) {
      result->Error("getSystemDevices", winrt::to_string(e.message()));
    } catch (const std::exception& e) {
      result->Error("getSystemDevices", e.what());
    }
    co_return;
}

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
      GetSystemDevicesAsync(std::move(result));
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
