#include <ArduinoBLE.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Scanning...");
  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }

  BLE.scanForUuid("");  // Scan for all services, or provide specific UUID if known
}

void loop() {
  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    Serial.print("Found device: ");
    Serial.println(peripheral.localName());

    Serial.println("Service UUIDs:");
    for (int i = 0; i < peripheral.serviceCount(); i++) {
      BLEService service = peripheral.service(i);
      Serial.println(service.uuid());
      Serial.println("Characteristic UUIDs:");
      for (int j = 0; j < service.characteristicCount(); j++) {
        BLECharacteristic characteristic = service.characteristic(j);
        Serial.println(characteristic.uuid());
      }
    }
  }
}
