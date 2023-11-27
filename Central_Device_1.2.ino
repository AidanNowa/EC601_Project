#include <ArduinoBLE.h>

#define BLE_NICLA_UUID(val) ("19b10000-" val "-537e-4f6c-d104768a1214")
#define BLE_NICLA_2_UUID(val) ("20b10000-" val "-537e-4f6c-d104768a1214")

BLEDevice peripheral_1, peripheral_2;

int connectedDevices = 0;

const char* peripheralServiceUUID = BLE_NICLA_UUID("0000");
const char* accelerometerCharacteristicUuid = BLE_NICLA_UUID("5001");
const char* gyroscopeCharacteristicUuid = BLE_NICLA_UUID("6001");
const char* quaternionCharacteristicUuid = BLE_NICLA_UUID("7001");
const char* rgbLedCharacteristicUuid = BLE_NICLA_UUID("8001");
const char* orientationCharacteristicUuid = BLE_NICLA_UUID("9001");

const char* peripheralServiceUUID_2 = BLE_NICLA_2_UUID("0000");
const char* accelerometerCharacteristicUuid_2 = BLE_NICLA_2_UUID("5001");
const char* gyroscopeCharacteristicUuid_2 = BLE_NICLA_2_UUID("6001");
const char* quaternionCharacteristicUuid_2 = BLE_NICLA_2_UUID("7001");
const char* rgbLedCharacteristicUuid_2 = BLE_NICLA_2_UUID("8001");
const char* orientationCharacteristicUuid_2 = BLE_NICLA_2_UUID("9001");

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }
  BLE.setLocalName("Nano 33 BLE (Central)"); 
  Serial.println("Arduino Nano 33 BLE Sense (Central Device)");
  Serial.println(" ");
}

void loop() {

  connectToPeripheral();
}
void connectToPeripheral(){

  do{
    BLE.scanForUuid(peripheralServiceUUID);
    peripheral_1 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_2);
    peripheral_2 = BLE.available();
  } while(!peripheral_1 && !peripheral_2);

  if (peripheral_1 && peripheral_2) {
    Serial.println("* Peripheral devices found!");
    Serial.print("* Device 1 name: ");
    Serial.println(peripheral_1.localName());
    Serial.print("* Device 2 name: ");
    Serial.println(peripheral_2.localName());
    Serial.print("* Advertised services UUID: ");
    Serial.println(peripheral_1.advertisedServiceUuid());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_2.advertisedServiceUuid());
    Serial.println(" ");
    BLE.stopScan();
    controlPeripheral(peripheral_1, peripheral_2);
  }
}

void controlPeripheral(BLEDevice peripheral, BLEDevice peripheral2){
  Serial.println(" Connecting to peripheral device...");

  if(peripheral_1.connect() && peripheral_2.connect()){
    Serial.println("Connected to peripheral devices!");
    Serial.println(" ");
  } 
  else{
    Serial.println("Connection to peripheral devices failed");
    Serial.println(" ");
    return;
  }
  Serial.println("--Discovering peripheral device attributes...");
  if (peripheral_1.discoverAttributes() && peripheral_2.discoverAttributes()) {
    Serial.println("* Peripheral device attributes discovered!");
    Serial.println(" ");
  } else {
    Serial.println("* Peripheral device attributes discovery failed!");
    Serial.println(" ");
    peripheral.disconnect();
    return;
  }

  // BLECharacteristic accelerometerCharacteristic = peripheral.characteristic(accelerometerCharacteristicUuid);
  // BLECharacteristic gyroscopeCharacteristic = peripheral.characteristic(gyroscopeCharacteristicUuid);
  // BLECharacteristic quaternionCharacteristic = peripheral.characteristic(quaternionCharacteristicUuid);
  // BLECharacteristic rgbLedCharacteristic = peripheral.characteristic(rgbLedCharacteristicUuid);
  
  BLECharacteristic orientationCharacteristic = peripheral_1.characteristic(orientationCharacteristicUuid);
  BLECharacteristic orientationCharacteristic_2 = peripheral_2.characteristic(orientationCharacteristicUuid_2);


  // if (accelerometerCharacteristic) {
  //   Serial.println("* Peripheral device does have accelerometer_type characteristic!");
  //   if(accelerometerCharacteristic.subscribe()){
  //     Serial.println("* accelerometer characteristic has been subscribed too!");
  //   }
  // } 
  // if (gyroscopeCharacteristic) {
  //   Serial.println("* Peripheral device does have gyroscope_type characteristic!");
  //   if(gyroscopeCharacteristic.subscribe()){
  //     Serial.println("* gyroscope characteristic has been subscribed too!");
  //   }
  // }
  // if (quaternionCharacteristic) {
  //   Serial.println("* Peripheral device does have quaternion_type characteristic!");
  //   if(quaternionCharacteristic.subscribe()){
  //     Serial.println("* quaternion characteristic has been subscribed too!");
  //   }
  // }
  if (orientationCharacteristic) {
    Serial.println("* Peripheral device does have orientation_type characteristic!");
    if(orientationCharacteristic.subscribe()){
      Serial.println("* orientation characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_2) {
    Serial.println("* Peripheral device does have orientation_type characteristic!");
    if(orientationCharacteristic_2.subscribe()){
      Serial.println("* orientation2 characteristic has been subscribed too!");
    }
  }

  while(peripheral.connected()){
    float ax, ay, az, gx, gy, gz, qw, qx, qy, qz, roll, pitch, yaw, roll_2, pitch_2, yaw_2;
    float accelerometerValues[] = {ax, ay, az};
    float gyroscopeValues[] = {gx, gy, gz};
    float quaternionValues[] = {qw, qx, qy, qz};

    float orientationValues[] = {roll, pitch, yaw};
    float orientationValues_2[] = {roll_2, pitch_2, yaw_2};
  
      // Serial.print("Accelerometer Data: ");
      // accelerometerCharacteristic.readValue(accelerometerValues, sizeof(accelerometerValues));
      // Serial.print("X: "); Serial.print(accelerometerValues[0]);
      // Serial.print(" Y: "); Serial.print(accelerometerValues[1]);
      // Serial.print(" Z: "); Serial.println(accelerometerValues[2]);
    
      // Serial.print("Gyroscope Data: ");
      // gyroscopeCharacteristic.readValue(gyroscopeValues, sizeof(gyroscopeValues));
      // Serial.print("X: "); Serial.print(gyroscopeValues[0]);
      // Serial.print(" Y: "); Serial.print(gyroscopeValues[1]);
      // Serial.print(" Z: "); Serial.println(gyroscopeValues[2]);
      
      // Serial.print("Quaternion Data: ");
      // quaternionCharacteristic.readValue(quaternionValues, sizeof(quaternionValues));
      // Serial.print("X: "); Serial.print(quaternionValues[0]);
      // Serial.print(" Y: "); Serial.print(quaternionValues[1]);
      // Serial.print(" Z: "); Serial.print(quaternionValues[2]);
      // Serial.print(" W: "); Serial.println(quaternionValues[3]);

      Serial.println("Orientation Data: ");
      orientationCharacteristic.readValue(orientationValues, sizeof(orientationValues));
      orientationCharacteristic_2.readValue(orientationValues_2, sizeof(orientationValues_2));
      Serial.print("Roll_1: "); Serial.print(orientationValues[0]);
      Serial.print(" Pitch_1: "); Serial.print(orientationValues[1]);
      Serial.print(" Yaw_1: "); Serial.println(orientationValues[2]);

      Serial.print("Roll_2: "); Serial.print(orientationValues_2[0]);
      Serial.print(" Pitch_2: "); Serial.print(orientationValues_2[1]);
      Serial.print(" Yaw_2: "); Serial.println(orientationValues_2[2]);
    }

}
