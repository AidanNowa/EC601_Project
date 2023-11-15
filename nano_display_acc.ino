#include <ArduinoBLE.h>

#define BLE_SENSE_UUID(val) ("19b10000-" val "-537e-4f6c-d104768a1214")

bool deviceConnected = false;
bool oldDeviceConnected = false;
BLEDevice peripheral;
BLEService service(BLE_SENSE_UUID("0000"));
const char* deviceServiceUuid = "19b10000-0000-537e-4f6c-d104768a1214";
//BLEService accelerometerService("19b10000-0000-537e-4f6c-d104768a1214");
//BLECharacteristic accelerometerCharacteristic(BLE_SENSE_UUID("5001"), BLERead | BLENotify, 3 * sizeof(float));  // Array of 3x 2 Bytes, XY
const char* accelerometerCharacteristicUuid = "19b10000-5001-537e-4f6c-d104768a1214";
const char* gyroscopeCharacteristicUuid = "19b10000-6001-537e-4f6c-d104768a1214";
const char* quaternionCharacteristicUuid = "19b10000-7001-537e-4f6c-d104768a1214";
const char* rgbLedCharacteristicUuid = "19b10000-8001-537e-4f6c-d104768a1214";

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }
  BLE.setLocalName("Nano 33 BLE (Central)"); 
  BLE.advertise();

  Serial.println("Arduino Nano 33 BLE Sense (Central Device)");
  Serial.println(" ");

  //BLE.scanForName("NiclaSenseME-4C4F"); // Replace with your device's local name
  //BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
}

void loop() {
  //peripheral = BLE.available();
  connectToPeripheral();
}
void connectToPeripheral(){

  do{
    BLE.scanForUuid(deviceServiceUuid);
    peripheral = BLE.available();
  } while(!peripheral);

  if (peripheral) {
    Serial.println("* Peripheral device found!");
    Serial.print("* Device MAC address: ");
    Serial.println(peripheral.address());
    Serial.print("* Device name: ");
    Serial.println(peripheral.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral.advertisedServiceUuid());
    Serial.println(" ");
    BLE.stopScan();
    controlPeripheral(peripheral);
  }
}

void controlPeripheral(BLEDevice peripheral){
  Serial.println(" Connecting to peripheral device...");

  if(peripheral.connect()){
    Serial.println("Connected to peripheral device!");
    Serial.println(" ");
  } 
  else{
    Serial.println("Connection to peripheral device failed");
    Serial.println(" ");
    return;
  }
  Serial.println("--Discovering peripheral device attributes...");
  if (peripheral.discoverAttributes()) {
    Serial.println("* Peripheral device attributes discovered!");
    Serial.println(" ");
  } else {
    Serial.println("* Peripheral device attributes discovery failed!");
    Serial.println(" ");
    peripheral.disconnect();
    return;
  }

  BLECharacteristic accelerometerCharacteristic = peripheral.characteristic(accelerometerCharacteristicUuid);
  BLECharacteristic gyroscopeCharacteristic = peripheral.characteristic(gyroscopeCharacteristicUuid);
  BLECharacteristic quaternionCharacteristic = peripheral.characteristic(quaternionCharacteristicUuid);
  BLECharacteristic rgbLedCharacteristic = peripheral.characteristic(rgbLedCharacteristicUuid);

  if (accelerometerCharacteristic) {
    Serial.println("* Peripheral device does have accelerometer_type characteristic!");
    if(accelerometerCharacteristic.subscribe()){
      Serial.println("* accelerometer characteristic has been subscribed too!");
    }
  } 
  if (gyroscopeCharacteristic) {
    Serial.println("* Peripheral device does have gyroscope_type characteristic!");
    if(gyroscopeCharacteristic.subscribe()){
      Serial.println("* gyroscope characteristic has been subscribed too!");
    }
  }
  if (quaternionCharacteristic) {
    Serial.println("* Peripheral device does have quaternion_type characteristic!");
    if(quaternionCharacteristic.subscribe()){
      Serial.println("* quaternion characteristic has been subscribed too!");
    }
  }

  while(peripheral.connected()){
    float ax, ay, az, gx, gy, gz, qw, qx, qy, qz;
    float accelerometerValues[] = {ax, ay, az};
    float gyroscopeValues[] = {gx, gy, gz};
    float quaternionValues[] = {qw, qx, qy, qz};
    //if (accelerometerCharacteristic.valueUpdated()) {
      Serial.print("Accelerometer Data: ");
      accelerometerCharacteristic.readValue(accelerometerValues, sizeof(accelerometerValues));
      Serial.print("X: "); Serial.print(accelerometerValues[0]);
      Serial.print(" Y: "); Serial.print(accelerometerValues[1]);
      Serial.print(" Z: "); Serial.println(accelerometerValues[2]);
    //}
      Serial.print("Gyroscope Data: ");
      gyroscopeCharacteristic.readValue(gyroscopeValues, sizeof(gyroscopeValues));
      Serial.print("X: "); Serial.print(gyroscopeValues[0]);
      Serial.print(" Y: "); Serial.print(gyroscopeValues[1]);
      Serial.print(" Z: "); Serial.println(gyroscopeValues[2]);
      
      Serial.print("Quaternion Data: ");
      quaternionCharacteristic.readValue(quaternionValues, sizeof(quaternionValues));
      Serial.print("W: "); Serial.print(quaternionValues[0]);
      Serial.print(" X: "); Serial.print(quaternionValues[1]);
      Serial.print(" Y: "); Serial.print(quaternionValues[2]);
      Serial.print(" Z: "); Serial.println(quaternionValues[3]);
  }




}
/*
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
    if (accelerometerCharacteristic.valueUpdated()) {
      Serial.print("Accelerometer Data: ");
      float x, y, z;
      float accelerometerValues[] = {x, y, z};
      accelerometerCharacteristic.readValue(accelerometerValues, sizeof(accelerometerValues));
      Serial.print("X: "); Serial.print(accelerometerValues[0]);
      Serial.print(" Y: "); Serial.print(accelerometerValues[1]);
      Serial.print(" Z: "); Serial.println(accelerometerValues[2]);
    }
  }
  //Serial.println("Not in data loop");
  delay(100);
}

void blePeripheralDisconnectHandler(BLEDevice central){
  Serial.println("Device Disconnected");
  deviceConnected = false;
}
*/
