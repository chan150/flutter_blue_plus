class BluetoothDevice {
  const BluetoothDevice();

  BluetoothRemoteGATTServer? get gatt => null;
}

class BluetoothRemoteGATTServer {
  const BluetoothRemoteGATTServer([this.uuid = '']);

  final String uuid;

  List<BluetoothRemoteGATTService> getPrimaryServices() {
    return [];
  }

  Future<void> connect() async {}

  Future<void> disconnect() async {}
}

class BluetoothRemoteGATTService {
  const BluetoothRemoteGATTService([this.uuid = '']);

  final String uuid;

  List<BluetoothRemoteGATTCharacteristic> getCharacteristics() {
    return [];
  }
}

class BluetoothRemoteGATTCharacteristic {
  const BluetoothRemoteGATTCharacteristic([this.uuid = '']);

  final String uuid;

  List<BluetoothRemoteGATTDescriptor> getDescriptors() {
    return [];
  }
}

class BluetoothRemoteGATTDescriptor {
  const BluetoothRemoteGATTDescriptor([this.uuid = '']);

  final String uuid;
}
