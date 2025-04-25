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

    ////////////////////////////////////////////////////////////
    // ███    ███  ███████  ████████  ██   ██   ██████   ██████
    // ████  ████  ██          ██     ██   ██  ██    ██  ██   ██
    // ██ ████ ██  █████       ██     ███████  ██    ██  ██   ██
    // ██  ██  ██  ██          ██     ██   ██  ██    ██  ██   ██
    // ██      ██  ███████     ██     ██   ██   ██████   ██████
    //
    //  ██████   █████   ██       ██
    // ██       ██   ██  ██       ██
    // ██       ███████  ██       ██
    // ██       ██   ██  ██       ██
    //  ██████  ██   ██  ███████  ███████

void FlutterBluePlusWindowsPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  const auto& method = method_call.method_name();
//  const auto& arguments = method_call.arguments();

  if (method == "setLogLevel") {
//    result->Success(flutter::EncodableValue(true));
//    return;
  }

  if (method == "setOptions") {
//    result->Success(flutter::EncodableValue(true));
//    return;
  }

  if (method == "flutterRestart") {
//    result->Success(flutter::EncodableValue(true));
//    return;
  }

  if (method == "connectedCount") {
//    result->Success(flutter::EncodableValue(true));
//    return;
  }

  if (method == "isSupported") {
  }

  if (method == "getAdapterName") {
  }

  if (method == "getAdapterState") {
//    flutter::EncodableMap response = {
//        {"adapter_state", 4}
//    };
//    result->Success(flutter::EncodableValue(response));
  }

  if (method == "startScan") {
    
  }

  if (method == "stopScan") {
  }

  if (method == "getSystemDevices") {
    using namespace winrt::Windows::Devices::Enumeration;
    using namespace winrt::Windows::Devices::Bluetooth;
    using namespace winrt::Windows::Foundation;

    auto asyncOp = DeviceInformation::FindAllAsync(BluetoothLEDevice::GetDeviceSelector());

//    flutter::EncodableList deviceList(0);
//    flutter::EncodableMap response = {
//        {flutter::EncodableValue("devices"), deviceList}
//    };
//    result->Success(flutter::EncodableValue(response));
//    return;

    asyncOp.Completed([result = std::move(result)](auto const& op, auto const& status) mutable {
        if (status == winrt::Windows::Foundation::AsyncStatus::Completed) {
            auto devices = op.GetResults();
            flutter::EncodableList deviceList(0);
//            std::cout << &devices << std::endl;
            // for (const auto& device : devices) {
            //     flutter::EncodableMap devMap;
            //     devMap[flutter::EncodableValue("remote_id")] = flutter::EncodableValue(winrt::to_string(device.Id()));
            //     devMap[flutter::EncodableValue("platform_name")] = flutter::EncodableValue(winrt::to_string(device.Name()));
            //     deviceList.push_back(flutter::EncodableValue(devMap));
            // }
            flutter::EncodableMap response = {
                {flutter::EncodableValue("devices"), deviceList}
            };
            result->Success(flutter::EncodableValue(response));
        } else {
            result->Error("getSystemDevices", "Failed to get BLE devices");
        }
    });
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

}  // namespace flutter_blue_plus_windows
