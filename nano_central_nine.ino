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
const char* peripheralServiceUUID_LK = BLE_NICLA_UUID("0002");
const char* accelerometerCharacteristicUuid_LK = BLE_NICLA_UUID("5002");
const char* gyroscopeCharacteristicUuid_LK = BLE_NICLA_UUID("6002");
const char* quaternionCharacteristicUuid_LK = BLE_NICLA_UUID("7002");
const char* rgbLedCharacteristicUuid_LK = BLE_NICLA_UUID("8002");
const char* orientationCharacteristicUuid_LK = BLE_NICLA_UUID("9002");

// Left Hip
const char* peripheralServiceUUID_LH = BLE_NICLA_UUID("0003");
const char* accelerometerCharacteristicUuid_LH = BLE_NICLA_UUID("5003");
const char* gyroscopeCharacteristicUuid_LH = BLE_NICLA_UUID("6003");
const char* quaternionCharacteristicUuid_LH = BLE_NICLA_UUID("7003");
const char* rgbLedCharacteristicUuid_LH = BLE_NICLA_UUID("8003");
const char* orientationCharacteristicUuid_LH = BLE_NICLA_UUID("9003");

// Right Ankle
const char* peripheralServiceUUID_RA = BLE_NICLA_UUID("0004");
const char* accelerometerCharacteristicUuid_RA = BLE_NICLA_UUID("5004");
const char* gyroscopeCharacteristicUuid_RA = BLE_NICLA_UUID("6004");
const char* quaternionCharacteristicUuid_RA = BLE_NICLA_UUID("7004");
const char* rgbLedCharacteristicUuid_RA = BLE_NICLA_UUID("8004");
const char* orientationCharacteristicUuid_RA = BLE_NICLA_UUID("9004");

// Right Knee
const char* peripheralServiceUUID_RK = BLE_NICLA_UUID("0005");
const char* accelerometerCharacteristicUuid_RK = BLE_NICLA_UUID("5005");
const char* gyroscopeCharacteristicUuid_RK = BLE_NICLA_UUID("6005");
const char* quaternionCharacteristicUuid_RK = BLE_NICLA_UUID("7005");
const char* rgbLedCharacteristicUuid_RK = BLE_NICLA_UUID("8005");
const char* orientationCharacteristicUuid_RK = BLE_NICLA_UUID("9005");

// Right Hip
const char* peripheralServiceUUID_RH = BLE_NICLA_UUID("0006");
const char* accelerometerCharacteristicUuid_RH = BLE_NICLA_UUID("5006");
const char* gyroscopeCharacteristicUuid_RH = BLE_NICLA_UUID("6006");
const char* quaternionCharacteristicUuid_RH = BLE_NICLA_UUID("7006");
const char* rgbLedCharacteristicUuid_RH = BLE_NICLA_UUID("8006");
const char* orientationCharacteristicUuid_RH = BLE_NICLA_UUID("9006");

// Lower Back
const char* peripheralServiceUUID_LB = BLE_NICLA_UUID("0007");
const char* accelerometerCharacteristicUuid_LB = BLE_NICLA_UUID("5007");
const char* gyroscopeCharacteristicUuid_LB = BLE_NICLA_UUID("6007");
const char* quaternionCharacteristicUuid_LB = BLE_NICLA_UUID("7007");
const char* rgbLedCharacteristicUuid_LB = BLE_NICLA_UUID("8007");
const char* orientationCharacteristicUuid_LB = BLE_NICLA_UUID("9007");

// Mid Back
const char* peripheralServiceUUID_MB = BLE_NICLA_UUID("0008");
const char* accelerometerCharacteristicUuid_MB = BLE_NICLA_UUID("5008");
const char* gyroscopeCharacteristicUuid_MB = BLE_NICLA_UUID("6008");
const char* quaternionCharacteristicUuid_MB = BLE_NICLA_UUID("7008");
const char* rgbLedCharacteristicUuid_MB = BLE_NICLA_UUID("8008");
const char* orientationCharacteristicUuid_MB = BLE_NICLA_UUID("9008");

// Upper Back
const char* peripheralServiceUUID_UB = BLE_NICLA_UUID("0009");
const char* accelerometerCharacteristicUuid_UB = BLE_NICLA_UUID("5009");
const char* gyroscopeCharacteristicUuid_UB = BLE_NICLA_UUID("6009");
const char* quaternionCharacteristicUuid_UB = BLE_NICLA_UUID("7009");
const char* rgbLedCharacteristicUuid_UB = BLE_NICLA_UUID("8009");
const char* orientationCharacteristicUuid_UB = BLE_NICLA_UUID("9009");

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

  //do{
    Serial.println("Scanning...");
    Serial.println("Scanning for 1");
    while(!peripheral_1){
      BLE.scanForUuid(peripheralServiceUUID_LA);
      if(peripheral_1 = BLE.available()){
        Serial.println("Device 1 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 2");
    while(!peripheral_2){
      BLE.scanForUuid(peripheralServiceUUID_LK);
      if(peripheral_2 = BLE.available()){
        Serial.println("Device 2 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 3");
    while(!peripheral_3){
      BLE.scanForUuid(peripheralServiceUUID_LH);
      if(peripheral_3 = BLE.available()){
        Serial.println("Device 3 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 4");
    while(!peripheral_4){
      BLE.scanForUuid(peripheralServiceUUID_RA);
      if(peripheral_4 = BLE.available()){
        Serial.println("Device 4 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 5");
    while(!peripheral_5){
      BLE.scanForUuid(peripheralServiceUUID_RK);
      if(peripheral_5 = BLE.available()){
        Serial.println("Device 5 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 6");
    while(!peripheral_6){
      BLE.scanForUuid(peripheralServiceUUID_RH);
      if(peripheral_6 = BLE.available()){
        Serial.println("Device 6 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 7");
    while(!peripheral_7){
      BLE.scanForUuid(peripheralServiceUUID_LB);
      if(peripheral_7 = BLE.available()){
        Serial.println("Device 7 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 8");
    while(!peripheral_8){
      BLE.scanForUuid(peripheralServiceUUID_MB);
      if(peripheral_8 = BLE.available()){
        Serial.println("Device 8 found");
      }
    }
    //delay(10);
    Serial.println("Scanning for 9");
    while(!peripheral_9){
      BLE.scanForUuid(peripheralServiceUUID_UB);
      if(peripheral_9 = BLE.available()){
        Serial.println("Device 9 found");
      }
    }
    //delay(10);

  //} while(!peripheral_1 && !peripheral_2 && !peripheral_3 && !peripheral_4 && !peripheral_5 && !peripheral_6 && !peripheral_7 && !peripheral_8 && !peripheral_9);

  if (peripheral_1 && peripheral_2 && peripheral_3 && peripheral_4 && peripheral_5 && peripheral_6 && peripheral_7 && peripheral_8 && peripheral_9) {
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

void controlPeripheral(BLEDevice periphera_l, BLEDevice peripheral_2, BLEDevice peripheral_3, BLEDevice peripheral_4, BLEDevice peripheral_5, BLEDevice peripheral_6, BLEDevice peripheral_7, BLEDevice peripheral_8, BLEDevice peripheral_9){
  Serial.println(" Connecting to peripheral device...");

  //if(peripheral_1.connect() && peripheral_2.connect() && peripheral_3.connect() && peripheral_4.connect() && peripheral_5.connect() && peripheral_6.connect() && peripheral_7.connect() && peripheral_8.connect() && peripheral_9.connect()){
  //  Serial.println("Connected to ALL peripheral devices!");
  //  Serial.println(" ");
  //}

  while(!peripheral_1.connect()){
    Serial.println("Connecting to 1");
    peripheral_1.connect();
  }
  Serial.println("Decive 1 connected");

  while(!peripheral_2.connect()){
    Serial.println("Connecting to 2");
    peripheral_2.connect();
  }
  Serial.println("Decive 2 connected");

  while(!peripheral_3.connect()){
    Serial.println("Connecting to 3");
    peripheral_3.connect();
  }
  Serial.println("Decive 3 connected");

  while(!peripheral_4.connect()){
    Serial.println("Connecting to 4");
    peripheral_4.connect();
  }
  Serial.println("Decive 4 connected");

  while(!peripheral_5.connect()){
    Serial.println("Connecting to 5");
    peripheral_5.connect();
  }
  Serial.println("Decive 5 connected");

  while(!peripheral_6.connect()){
    Serial.println("Connecting to 6");
    peripheral_6.connect();
  }
  Serial.println("Decive 6 connected");

  while(!peripheral_7.connect()){
    Serial.println("Connecting to 7");
    peripheral_7.connect();
  }
  Serial.println("Decive 7 connected");

  while(!peripheral_8.connect()){
    Serial.println("Connecting to 8");
    peripheral_8.connect();
  }
  Serial.println("Decive 8 connected");

  while(!peripheral_9.connect()){
    Serial.println("Connecting to 9");
    peripheral_9.connect();
  }
  Serial.println("Decive 9 connected");

  //else{
  //  Serial.println("Connection to peripheral devices failed");
  //  Serial.println(" ");
  //  return;
  //}
  Serial.println("--Discovering peripheral device attributes...");
  if (peripheral_1.discoverAttributes() && peripheral_2.discoverAttributes() && peripheral_3.discoverAttributes() && peripheral_4.discoverAttributes() && peripheral_5.discoverAttributes() && peripheral_6.discoverAttributes() && peripheral_7.discoverAttributes() && peripheral_8.discoverAttributes() && peripheral_9.discoverAttributes()) {
    Serial.println("* Peripheral device attributes discovered!");
    Serial.println(" ");
  } else {
    Serial.println("* Peripheral device attributes discovery failed!");
    Serial.println(" ");
    peripheral_1.disconnect();
    peripheral_2.disconnect();
    peripheral_3.disconnect();
    peripheral_4.disconnect();
    peripheral_5.disconnect();
    peripheral_6.disconnect();
    peripheral_7.disconnect();
    peripheral_8.disconnect();
    peripheral_9.disconnect();

    return;
  }

  // BLECharacteristic accelerometerCharacteristic = peripheral.characteristic(accelerometerCharacteristicUuid);
  // BLECharacteristic gyroscopeCharacteristic = peripheral.characteristic(gyroscopeCharacteristicUuid);
  // BLECharacteristic quaternionCharacteristic = peripheral.characteristic(quaternionCharacteristicUuid);
  // BLECharacteristic rgbLedCharacteristic = peripheral.characteristic(rgbLedCharacteristicUuid);
  
  //BLECharacteristic orientationCharacteristic_1 = peripheral_1.characteristic(orientationCharacteristicUuid_LA);
  //BLECharacteristic orientationCharacteristic_2 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_3 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_4 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_5 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_6 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_7 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_8 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);
  //BLECharacteristic orientationCharacteristic_9 = peripheral_2.characteristic(orientationCharacteristicUuid_LK);

  BLECharacteristic quaternionCharacteristic_1 = peripheral_1.characteristic(quaternionCharacteristicUuid_LA);
  BLECharacteristic quaternionCharacteristic_2 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_3 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_4 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_5 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_6 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_7 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_8 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);
  BLECharacteristic quaternionCharacteristic_9 = peripheral_2.characteristic(quaternionCharacteristicUuid_LK);


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
  if (quaternionCharacteristic_1) {
    Serial.println("* Peripheral device 1 does have orientation_type characteristic!");
    if(quaternionCharacteristic_1.subscribe()){
      Serial.println("* orientation characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_2) {
    Serial.println("* Peripheral device 2 does have orientation_type characteristic!");
    if(quaternionCharacteristic_2.subscribe()){
      Serial.println("* orientation 2 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_3) {
    Serial.println("* Peripheral device 3 does have orientation_type characteristic!");
    if(quaternionCharacteristic_3.subscribe()){
      Serial.println("* orientation 3 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_4) {
    Serial.println("* Peripheral device 4 does have orientation_type characteristic!");
    if(quaternionCharacteristic_4.subscribe()){
      Serial.println("* orientation 4 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_5) {
    Serial.println("* Peripheral device 5 does have orientation_type characteristic!");
    if(quaternionCharacteristic_5.subscribe()){
      Serial.println("* orientation 5 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_6) {
    Serial.println("* Peripheral device 6 does have orientation_type characteristic!");
    if(quaternionCharacteristic_6.subscribe()){
      Serial.println("* orientation2 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_7) {
    Serial.println("* Peripheral device 7 does have orientation_type characteristic!");
    if(quaternionCharacteristic_7.subscribe()){
      Serial.println("* orientation 7 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_8) {
    Serial.println("* Peripheral device 8 does have orientation_type characteristic!");
    if(quaternionCharacteristic_8.subscribe()){
      Serial.println("* orientation 8 characteristic has been subscribed too!");
    }
  }

  if (quaternionCharacteristic_9) {
    Serial.println("* Peripheral device 9 does have orientation_type characteristic!");
    if(quaternionCharacteristic_9.subscribe()){
      Serial.println("* orientation 9 characteristic has been subscribed too!");
    }
  }

  while(peripheral_1.connected() && peripheral_2.connected() && peripheral_3.connected() && peripheral_4.connected() && peripheral_5.connected() && peripheral_6.connected() && peripheral_7.connected() && peripheral_8.connected() && peripheral_9.connected()){
    float ax, ay, az, gx, gy, gz, qw, qx, qy, qz, roll, pitch, yaw, roll_2, pitch_2, yaw_2;
    float accelerometerValues[] = {ax, ay, az};
    float gyroscopeValues[] = {gx, gy, gz};
    

    float qx1, qy1, qz1, qw1, qx2, qy2, qz2, qw2, qx3, qy3, qz3, qw3, qx4, qy4, qz4, qw4, qx5, qy5, qz5, qw5, qx6, qy6, qz6, qw6, qx7, qy7, qz7, qw7, qx8, qy8, qz8, qw8, qx9, qy9, qz9, qw9;
    float quaternionValues_1[] = {qx1, qy1, qz1, qw1};
    float quaternionValues_2[] = {qx2, qy2, qz2, qw2};
    float quaternionValues_3[] = {qx3, qy3, qz3, qw3};
    float quaternionValues_4[] = {qx4, qy4, qz4, qw4};
    float quaternionValues_5[] = {qx5, qy5, qz5, qw5};
    float quaternionValues_6[] = {qx6, qy6, qz6, qw6};
    float quaternionValues_7[] = {qx7, qy7, qz7, qw7};
    float quaternionValues_8[] = {qx8, qy8, qz8, qw8};
    float quaternionValues_9[] = {qx9, qy9, qz9, qw9};

    //float orientationValues_1[] = {roll_1, pitch_1, yaw_1};
    //float orientationValues_2[] = {roll_2, pitch_2, yaw_2};
    //float orientationValues_3[] = {roll_3, pitch_3, yaw_3};
    //float orientationValues_4[] = {roll_4, pitch_4, yaw_4};
    //float orientationValues_5[] = {roll_5, pitch_5, yaw_5};
    //float orientationValues_6[] = {roll_6, pitch_6, yaw_6};
    //float orientationValues_7[] = {roll_7, pitch_7, yaw_7};
    //float orientationValues_8[] = {roll_8, pitch_8, yaw_8};
    //float orientationValues_9[] = {roll_9, pitch_9, yaw_9};
  
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
      quaternionCharacteristic_1.readValue(quaternionValues_1, sizeof(quaternionValues_1));
      quaternionCharacteristic_2.readValue(quaternionValues_2, sizeof(quaternionValues_2));
      quaternionCharacteristic_3.readValue(quaternionValues_3, sizeof(quaternionValues_3));
      quaternionCharacteristic_4.readValue(quaternionValues_4, sizeof(quaternionValues_4));
      quaternionCharacteristic_5.readValue(quaternionValues_5, sizeof(quaternionValues_5));
      quaternionCharacteristic_6.readValue(quaternionValues_6, sizeof(quaternionValues_6));
      quaternionCharacteristic_7.readValue(quaternionValues_7, sizeof(quaternionValues_7));
      quaternionCharacteristic_8.readValue(quaternionValues_8, sizeof(quaternionValues_8));
      quaternionCharacteristic_9.readValue(quaternionValues_9, sizeof(quaternionValues_9));

      Serial.println("Sensor 1: ");
      Serial.print(quaternionValues_1[0]);
      Serial.print(quaternionValues_1[1]);
      Serial.print(quaternionValues_1[2]);
      Serial.print(quaternionValues_1[3]);
      Serial.println(" ");

      Serial.println("Sensor 2: ");
      Serial.print(quaternionValues_2[0]);
      Serial.print(quaternionValues_2[1]);
      Serial.print(quaternionValues_2[2]);
      Serial.print(quaternionValues_2[3]);
      Serial.println(" ");

      Serial.println("Sensor 3: ");
      Serial.print(quaternionValues_3[0]);
      Serial.print(quaternionValues_3[1]);
      Serial.print(quaternionValues_3[2]);
      Serial.print(quaternionValues_3[3]);
      Serial.println(" ");

      Serial.println("Sensor 4: ");
      Serial.print(quaternionValues_4[0]);
      Serial.print(quaternionValues_4[1]);
      Serial.print(quaternionValues_4[2]);
      Serial.print(quaternionValues_4[3]);
      Serial.println(" ");

      Serial.println("Sensor 5: ");
      Serial.print(quaternionValues_5[0]);
      Serial.print(quaternionValues_5[1]);
      Serial.print(quaternionValues_5[2]);
      Serial.print(quaternionValues_5[3]);
      Serial.println(" ");

      Serial.println("Sensor 6: ");
      Serial.print(quaternionValues_6[0]);
      Serial.print(quaternionValues_6[1]);
      Serial.print(quaternionValues_6[2]);
      Serial.print(quaternionValues_6[3]);
      Serial.println(" ");

      Serial.println("Sensor 7: ");
      Serial.print(quaternionValues_7[0]);
      Serial.print(quaternionValues_7[1]);
      Serial.print(quaternionValues_7[2]);
      Serial.print(quaternionValues_7[3]);
      Serial.println(" ");

      Serial.println("Sensor 8: ");
      Serial.print(quaternionValues_8[0]);
      Serial.print(quaternionValues_8[1]);
      Serial.print(quaternionValues_8[2]);
      Serial.print(quaternionValues_8[3]);
      Serial.println(" ");

      Serial.println("Sensor 9: ");
      Serial.print(quaternionValues_9[0]);
      Serial.print(quaternionValues_9[1]);
      Serial.print(quaternionValues_9[2]);
      Serial.print(quaternionValues_9[3]);
      Serial.println(" ");




      //Serial.print("Roll_1: "); Serial.print(orientationValues_1[0]);
      //Serial.print(" Pitch_1: "); Serial.print(orientationValues_1[1]);
      //Serial.print(" Yaw_1: "); Serial.println(orientationValues_1[2]);

      //Serial.print("Roll_2: "); Serial.print(orientationValues_2[0]);
      //Serial.print(" Pitch_2: "); Serial.print(orientationValues_2[1]);
      //Serial.print(" Yaw_2: "); Serial.println(orientationValues_2[2]);
      
      //Serial.print("Roll_3: "); Serial.print(orientationValues_3[0]);
      //Serial.print(" Pitch_3: "); Serial.print(orientationValues_3[1]);
      //Serial.print(" Yaw_3: "); Serial.println(orientationValues_3[2]);
      
      //Serial.print("Roll_4: "); Serial.print(orientationValues_4[0]);
      //Serial.print(" Pitch_4: "); Serial.print(orientationValues_4[1]);
      //Serial.print(" Yaw_4: "); Serial.println(orientationValues_4[2]);
      
      //Serial.print("Roll_5: "); Serial.print(orientationValues_5[0]);
      //Serial.print(" Pitch_5: "); Serial.print(orientationValues_5[1]);
      //Serial.print(" Yaw_5: "); Serial.println(orientationValues_5[2]);
      
      //Serial.print("Roll_6: "); Serial.print(orientationValues_6[0]);
      //Serial.print(" Pitch_6: "); Serial.print(orientationValues_6[1]);
      //Serial.print(" Yaw_6: "); Serial.println(orientationValues_6[2]);
      
      //Serial.print("Roll_7: "); Serial.print(orientationValues_7[0]);
      //Serial.print(" Pitch_7: "); Serial.print(orientationValues_7[1]);
      //Serial.print(" Yaw_7: "); Serial.println(orientationValues_7[2]);
      
      //Serial.print("Roll_8: "); Serial.print(orientationValues_8[0]);
      //Serial.print(" Pitch_8: "); Serial.print(orientationValues_8[1]);
      //Serial.print(" Yaw_8: "); Serial.println(orientationValues_8[2]);
      
      //Serial.print("Roll_9: "); Serial.print(orientationValues_9[0]);
      //Serial.print(" Pitch_9: "); Serial.print(orientationValues_9[1]);
      //Serial.print(" Yaw_9: "); Serial.println(orientationValues_9[2]);
    }

}