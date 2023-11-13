#include <ArduinoBLE.h>

#define BLE_SENSE_UUID(val) ("19b10000-" val "-537e-4f6c-d104768a1214")

bool deviceConnected = false;
bool oldDeviceConnected = false;
BLEDevice peripheral;
BLEService accelerometerService("19b10000-0000-537e-4f6c-d104768a1214");
BLECharacteristic accelerometerCharacteristic(BLE_SENSE_UUID("5001"), BLERead | BLENotify, 3 * sizeof(float));  // Array of 3x 2 Bytes, XY

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }

  BLE.scanForName("NiclaSenseME-4C4F"); // Replace with your device's local name
  BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
}

void loop() {
  peripheral = BLE.available();

  if (peripheral) {
    Serial.println("Connecting...");
    if (peripheral.localName() == "NiclaSenseME-4C4F") {
      Serial.println("Name Match");
      if (peripheral.connect()) {
        Serial.println("Connected to device!");
        deviceConnected = true;
        accelerometerService = peripheral.service(accelerometerService);
        accelerometerCharacteristic = accelerometerService.characteristic(accelerometerCharacteristic);
        accelerometerCharacteristic.subscribe();
      }
    }
  }

  if (deviceConnected && !oldDeviceConnected) {
    Serial.println("Connected to device!");
    oldDeviceConnected = true;
  }

  if (deviceConnected) {
    //if (accelerometerCharacteristic.valueUpdated()) {
      Serial.print("Accelerometer Data: ");
      float x, y, z;
      float accelerometerValues[] = {x, y, z};
      accelerometerCharacteristic.readValue(accelerometerValues, sizeof(accelerometerValues));
      Serial.print("X: "); Serial.print(accelerometerValues[0]);
      Serial.print(" Y: "); Serial.print(accelerometerValues[1]);
      Serial.print(" Z: "); Serial.println(accelerometerValues[2]);
    //}
  }
  //Serial.println("Not in data loop");
  delay(100);
}

void blePeripheralDisconnectHandler(BLEDevice central){
  Serial.println("Device Disconnected");
  deviceConnected = false;
}
