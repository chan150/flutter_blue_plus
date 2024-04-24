import 'package:flutter_blue_plus/flutter_blue_plus.dart';

extension BluetoothCharacteristicExtension on BluetoothCharacteristic {
  BmBluetoothCharacteristic toProto() {
    return BmBluetoothCharacteristic(
      remoteId: DeviceIdentifier(remoteId.str),
      serviceUuid: serviceUuid,
      secondaryServiceUuid: secondaryServiceUuid,
      characteristicUuid: characteristicUuid,
      descriptors: [for (final d in descriptors) d.toProto()],
      properties: properties.toProto(),
    );
  }
}
