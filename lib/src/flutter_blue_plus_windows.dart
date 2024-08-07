part of flutter_blue_plus;

class FBPWindows extends FBPPlatform {
  static void registerWith() {
    FBPPlatform.instance = FBPWindows();
  }

}

abstract class FBPPlatform extends PlatformInterface {
  FBPPlatform() : super(token: _token);

  static final Object _token = Object();

  static FBPPlatform _instance = FBPProvider();

  static FBPPlatform get instance => _instance;

  static set instance(FBPPlatform instance) {
    PlatformInterface.verify(instance, _token);
    _instance = instance;
  }
}

class FBPProvider extends FBPPlatform {
  platform.Platform _platform = const platform.LocalPlatform();

  MethodChannel methodChannel =
      const MethodChannel('flutter_blue_plus/methods');
}
