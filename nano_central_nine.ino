#include <ArduinoBLE.h>

#define BLE_NICLA_UUID(val) ("19b10000-" val "-537e-4f6c-d104768a1214")

BLEDevice peripheral_1, peripheral_2, peripheral_3, peripheral_4, peripheral_5, peripheral_6, peripheral_7, peripheral_8, peripheral_9;

int connectedDevices = 0;

// Left Ankle
const char* peripheralServiceUUID_LA = BLE_NICLA_UUID("0001");
const char* accelerometerCharacteristicUuid_LA = BLE_NICLA_UUID("5001");
const char* gyroscopeCharacteristicUuid_LA = BLE_NICLA_UUID("6001");
const char* quaternionCharacteristicUuid_LA = BLE_NICLA_UUID("7001");
const char* rgbLedCharacteristicUuid_LA = BLE_NICLA_UUID("8001");
const char* orientationCharacteristicUuid_LA = BLE_NICLA_UUID("9001");

// Left Knee
const char* peripheralServiceUUID_LK = BLE_NICLA_2_UUID("0002");
const char* accelerometerCharacteristicUuid_LK = BLE_NICLA_2_UUID("5002");
const char* gyroscopeCharacteristicUuid_LK = BLE_NICLA_2_UUID("6002");
const char* quaternionCharacteristicUuid_LK = BLE_NICLA_2_UUID("7002");
const char* rgbLedCharacteristicUuid_LK = BLE_NICLA_2_UUID("8002");
const char* orientationCharacteristicUuid_LK = BLE_NICLA_2_UUID("9002");

// Left Hip
const char* peripheralServiceUUID_LH = BLE_NICLA_2_UUID("0003");
const char* accelerometerCharacteristicUuid_LH = BLE_NICLA_2_UUID("5003");
const char* gyroscopeCharacteristicUuid_LH = BLE_NICLA_2_UUID("6003");
const char* quaternionCharacteristicUuid_LH = BLE_NICLA_2_UUID("7003");
const char* rgbLedCharacteristicUuid_LH = BLE_NICLA_2_UUID("8003");
const char* orientationCharacteristicUuid_LH = BLE_NICLA_2_UUID("9003");

// Right Ankle
const char* peripheralServiceUUID_RA = BLE_NICLA_2_UUID("0004");
const char* accelerometerCharacteristicUuid_RA = BLE_NICLA_2_UUID("5004");
const char* gyroscopeCharacteristicUuid_RA = BLE_NICLA_2_UUID("6004");
const char* quaternionCharacteristicUuid_RA = BLE_NICLA_2_UUID("7004");
const char* rgbLedCharacteristicUuid_RA = BLE_NICLA_2_UUID("8004");
const char* orientationCharacteristicUuid_RA = BLE_NICLA_2_UUID("9004");

// Right Knee
const char* peripheralServiceUUID_RK = BLE_NICLA_2_UUID("0005");
const char* accelerometerCharacteristicUuid_RK = BLE_NICLA_2_UUID("5005");
const char* gyroscopeCharacteristicUuid_RK = BLE_NICLA_2_UUID("6005");
const char* quaternionCharacteristicUuid_RK = BLE_NICLA_2_UUID("7005");
const char* rgbLedCharacteristicUuid_RK = BLE_NICLA_2_UUID("8005");
const char* orientationCharacteristicUuid_RK = BLE_NICLA_2_UUID("9005");

// Right Hip
const char* peripheralServiceUUID_RH = BLE_NICLA_2_UUID("0006");
const char* accelerometerCharacteristicUuid_RH = BLE_NICLA_2_UUID("5006");
const char* gyroscopeCharacteristicUuid_RH = BLE_NICLA_2_UUID("6006");
const char* quaternionCharacteristicUuid_RH = BLE_NICLA_2_UUID("7006");
const char* rgbLedCharacteristicUuid_RH = BLE_NICLA_2_UUID("8006");
const char* orientationCharacteristicUuid_RH = BLE_NICLA_2_UUID("9006");

// Lower Back
const char* peripheralServiceUUID_LB = BLE_NICLA_2_UUID("0007");
const char* accelerometerCharacteristicUuid_LB = BLE_NICLA_2_UUID("5007");
const char* gyroscopeCharacteristicUuid_LB = BLE_NICLA_2_UUID("6007");
const char* quaternionCharacteristicUuid_LB = BLE_NICLA_2_UUID("7007");
const char* rgbLedCharacteristicUuid_LB = BLE_NICLA_2_UUID("8007");
const char* orientationCharacteristicUuid_LB = BLE_NICLA_2_UUID("9007");

// Mid Back
const char* peripheralServiceUUID_MB = BLE_NICLA_2_UUID("0008");
const char* accelerometerCharacteristicUuid_MB = BLE_NICLA_2_UUID("5008");
const char* gyroscopeCharacteristicUuid_MB = BLE_NICLA_2_UUID("6008");
const char* quaternionCharacteristicUuid_MB = BLE_NICLA_2_UUID("7008");
const char* rgbLedCharacteristicUuid_MB = BLE_NICLA_2_UUID("8008");
const char* orientationCharacteristicUuid_MB = BLE_NICLA_2_UUID("9008");

// Upper Back
const char* peripheralServiceUUID_UB = BLE_NICLA_2_UUID("0009");
const char* accelerometerCharacteristicUuid_UB = BLE_NICLA_2_UUID("5009");
const char* gyroscopeCharacteristicUuid_UB = BLE_NICLA_2_UUID("6009");
const char* quaternionCharacteristicUuid_UB = BLE_NICLA_2_UUID("7009");
const char* rgbLedCharacteristicUuid_UB = BLE_NICLA_2_UUID("8009");
const char* orientationCharacteristicUuid_UB = BLE_NICLA_2_UUID("9009");

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
    BLE.scanForUuid(peripheralServiceUUID_LA);
    peripheral_1 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_LK);
    peripheral_2 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_LH);
    peripheral_3 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_RA);
    peripheral_4 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_RK);
    peripheral_5 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_RH);
    peripheral_6 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_LB);
    peripheral_7 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_MB);
    peripheral_8 = BLE.available();
    BLE.scanForUuid(peripheralServiceUUID_UB);
    peripheral_9 = BLE.available();

  } while(!peripheral_1 && !peripheral_2 && !peripheral_3 && !peripheral_4 && !peripheral_5 && !peripheral_6 && !peripheral_7 && !peripheral_8 && !peripheral_9);

  if (peripheral_1 && peripheral_2) {
    Serial.println("* Peripheral devices found!");
    Serial.print("* Device 1 name: ");
    Serial.println(peripheral_1.localName());
    Serial.print("* Advertised services UUID: ");
    Serial.println(peripheral_1.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 2 name: ");
    Serial.println(peripheral_2.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_2.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 3 name: ");
    Serial.println(peripheral_3.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_3.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 4 name: ");
    Serial.println(peripheral_4.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_4.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 5 name: ");
    Serial.println(peripheral_5.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_5.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 6 name: ");
    Serial.println(peripheral_6.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_6.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 7 name: ");
    Serial.println(peripheral_7.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_7.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 8 name: ");
    Serial.println(peripheral_8.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_8.advertisedServiceUuid());
    Serial.println(" ");

    Serial.print("* Device 9 name: ");
    Serial.println(peripheral_9.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral_9.advertisedServiceUuid());
    Serial.println(" ");


    BLE.stopScan();
    controlPeripheral(peripheral_1, peripheral_2, peripheral_3, peripheral_4, peripheral_5, peripheral_6, peripheral_7, peripheral_8, peripheral_9);
  }
}

void controlPeripheral(BLEDevice peripheral, BLEDevice peripheral2){
  Serial.println(" Connecting to peripheral device...");

  if(peripheral_1.connect() && peripheral_2.connect() && peripheral_3.connect() && peripheral_4.connect() && peripheral_5.connect() && peripheral_6.connect() && peripheral_7.connect() && peripheral_8.connect() && peripheral_9.connect()){
    Serial.println("Connected to ALL peripheral devices!");
    Serial.println(" ");
  } 
  else{
    Serial.println("Connection to peripheral devices failed");
    Serial.println(" ");
    return;
  }
  Serial.println("--Discovering peripheral device attributes...");
  if (peripheral_1.discoverAttributes() && peripheral_2.discoverAttributes() && peripheral_3.discoverAttributes() && peripheral_4.discoverAttributes() && peripheral_5.discoverAttributes() && peripheral_6.discoverAttributes() && peripheral_7.discoverAttributes() && peripheral_8.discoverAttributes() && peripheral_9.discoverAttributes()) {
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
  
  BLECharacteristic orientationCharacteristic_1 = peripheral_1.characteristic(orientationCharacteristicUuid_LA);
  BLECharacteristic orientationCharacteristic_2 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_3 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_4 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_5 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_6 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_7 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_8 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  BLECharacteristic orientationCharacteristic_9 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);


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
  if (orientationCharacteristic_1) {
    Serial.println("* Peripheral device 1 does have orientation_type characteristic!");
    if(orientationCharacteristic.subscribe()){
      Serial.println("* orientation characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_2) {
    Serial.println("* Peripheral device 2 does have orientation_type characteristic!");
    if(orientationCharacteristic_2.subscribe()){
      Serial.println("* orientation 2 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_3) {
    Serial.println("* Peripheral device 3 does have orientation_type characteristic!");
    if(orientationCharacteristic_3.subscribe()){
      Serial.println("* orientation 3 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_4) {
    Serial.println("* Peripheral device 4 does have orientation_type characteristic!");
    if(orientationCharacteristic_4.subscribe()){
      Serial.println("* orientation 4 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_5) {
    Serial.println("* Peripheral device 5 does have orientation_type characteristic!");
    if(orientationCharacteristic_5.subscribe()){
      Serial.println("* orientation 5 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_6) {
    Serial.println("* Peripheral device 6 does have orientation_type characteristic!");
    if(orientationCharacteristic_6.subscribe()){
      Serial.println("* orientation2 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_7) {
    Serial.println("* Peripheral device 7 does have orientation_type characteristic!");
    if(orientationCharacteristic_7.subscribe()){
      Serial.println("* orientation 7 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_8) {
    Serial.println("* Peripheral device 8 does have orientation_type characteristic!");
    if(orientationCharacteristic_8.subscribe()){
      Serial.println("* orientation 8 characteristic has been subscribed too!");
    }
  }

  if (orientationCharacteristic_9) {
    Serial.println("* Peripheral device 9 does have orientation_type characteristic!");
    if(orientationCharacteristic_9.subscribe()){
      Serial.println("* orientation 9 characteristic has been subscribed too!");
    }
  }

  while(peripheral.connected()){
    float ax, ay, az, gx, gy, gz, qw, qx, qy, qz, roll, pitch, yaw, roll_2, pitch_2, yaw_2;
    float accelerometerValues[] = {ax, ay, az};
    float gyroscopeValues[] = {gx, gy, gz};
    float quaternionValues[] = {qw, qx, qy, qz};

    float orientationValues_1[] = {roll_1, pitch_1, yaw_1};
    float orientationValues_2[] = {roll_2, pitch_2, yaw_2};
    float orientationValues_3[] = {roll_3, pitch_3, yaw_3};
    float orientationValues_4[] = {roll_4, pitch_4, yaw_4};
    float orientationValues_5[] = {roll_5, pitch_5, yaw_5};
    float orientationValues_6[] = {roll_6, pitch_6, yaw_6};
    float orientationValues_7[] = {roll_7, pitch_7, yaw_7};
    float orientationValues_8[] = {roll_8, pitch_8, yaw_8};
    float orientationValues_9[] = {roll_9, pitch_9, yaw_9};
  
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
      orientationCharacteristic_1.readValue(orientationValues_1, sizeof(orientationValues_1));
      orientationCharacteristic_2.readValue(orientationValues_2, sizeof(orientationValues_2));
      orientationCharacteristic_3.readValue(orientationValues_3, sizeof(orientationValues_3));
      orientationCharacteristic_4.readValue(orientationValues_4, sizeof(orientationValues_4));
      orientationCharacteristic_5.readValue(orientationValues_5, sizeof(orientationValues_5));
      orientationCharacteristic_6.readValue(orientationValues_6, sizeof(orientationValues_6));
      orientationCharacteristic_7.readValue(orientationValues_7, sizeof(orientationValues_7));
      orientationCharacteristic_8.readValue(orientationValues_8, sizeof(orientationValues_8));
      orientationCharacteristic_9.readValue(orientationValues_9, sizeof(orientationValues_9));

      Serial.print("Roll_1: "); Serial.print(orientationValues_1[0]);
      Serial.print(" Pitch_1: "); Serial.print(orientationValues_1[1]);
      Serial.print(" Yaw_1: "); Serial.println(orientationValues_1[2]);

      Serial.print("Roll_2: "); Serial.print(orientationValues_2[0]);
      Serial.print(" Pitch_2: "); Serial.print(orientationValues_2[1]);
      Serial.print(" Yaw_2: "); Serial.println(orientationValues_2[2]);
      
      Serial.print("Roll_3: "); Serial.print(orientationValues_3[0]);
      Serial.print(" Pitch_3: "); Serial.print(orientationValues_3[1]);
      Serial.print(" Yaw_3: "); Serial.println(orientationValues_3[2]);
      
      Serial.print("Roll_4: "); Serial.print(orientationValues_4[0]);
      Serial.print(" Pitch_4: "); Serial.print(orientationValues_4[1]);
      Serial.print(" Yaw_4: "); Serial.println(orientationValues_4[2]);
      
      Serial.print("Roll_5: "); Serial.print(orientationValues_5[0]);
      Serial.print(" Pitch_5: "); Serial.print(orientationValues_5[1]);
      Serial.print(" Yaw_5: "); Serial.println(orientationValues_5[2]);
      
      Serial.print("Roll_6: "); Serial.print(orientationValues_6[0]);
      Serial.print(" Pitch_6: "); Serial.print(orientationValues_6[1]);
      Serial.print(" Yaw_6: "); Serial.println(orientationValues_6[2]);
      
      Serial.print("Roll_7: "); Serial.print(orientationValues_7[0]);
      Serial.print(" Pitch_7: "); Serial.print(orientationValues_7[1]);
      Serial.print(" Yaw_7: "); Serial.println(orientationValues_7[2]);
      
      Serial.print("Roll_8: "); Serial.print(orientationValues_8[0]);
      Serial.print(" Pitch_8: "); Serial.print(orientationValues_8[1]);
      Serial.print(" Yaw_8: "); Serial.println(orientationValues_8[2]);
      
      Serial.print("Roll_9: "); Serial.print(orientationValues_9[0]);
      Serial.print(" Pitch_9: "); Serial.print(orientationValues_9[1]);
      Serial.print(" Yaw_9: "); Serial.println(orientationValues_9[2]);
    }

}