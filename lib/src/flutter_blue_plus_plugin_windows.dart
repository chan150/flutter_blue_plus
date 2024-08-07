part of flutter_blue_plus;

class FlutterBluePlusPluginWindows extends FlutterBluePlusPlugin {
  static void registerWith() {
    // FlutterBluePlusPlugin._methodChannel = FlutterBluePlusPluginWindows();
  }
}

abstract class FBPPlatform extends PlatformInterface {
  FBPPlatform() : super(token: _token);

  static final Object _token = Object();

  static FBPPlatform _instance = FBPPlatformProvider();

  static FBPPlatform get instance => _instance;

  static set instance(FBPPlatform instance) {
    PlatformInterface.verify(instance, _token);
    _instance = instance;
  }
}

class FBPPlatformProvider extends FBPPlatform {
  platform.Platform _platform = const platform.LocalPlatform();

  MethodChannel methodChannel =
      const MethodChannel('plugins.flutter.io/path_provider');
}
