  #include "Nicla_System.h"
  #include "Arduino_BHY2.h"
  #include <ArduinoBLE.h>
  #include "Arduino.h"

  #define BLE_NICLA_UUID(val) ("19b10000-" val "-537e-4f6c-d104768a1214")

  BLEService service(BLE_NICLA_UUID("0008"));


  BLECharacteristic accelerometerCharacteristic(BLE_NICLA_UUID("5008"), BLERead | BLENotify, 3 * sizeof(float));  // Array of 3x 2 Bytes, XY
  BLECharacteristic gyroscopeCharacteristic(BLE_NICLA_UUID("6008"), BLERead | BLENotify, 3 * sizeof(float));    // Array of 3x 2 Bytes, XYZ
  BLECharacteristic quaternionCharacteristic(BLE_NICLA_UUID("7008"), BLERead | BLENotify, 4 * sizeof(float)); // Array of 4x 2 Bytes, XYZW
  BLECharacteristic orientationCharacteristic(BLE_NICLA_UUID("9008"), BLERead | BLENotify, 3 * sizeof(float));   // Array of 3x 2 Bytes, roll, pitch, yaw

  BLECharacteristic rgbLedCharacteristic(BLE_NICLA_UUID("8008"), BLERead | BLEWrite, 3 * sizeof(byte)); // Array of 3 bytes, RGB
  // String to calculate the local and device name
  

  SensorXYZ gyroscope(SENSOR_ID_GYRO);
  SensorXYZ accelerometer(SENSOR_ID_ACC);
  SensorQuaternion quaternion(SENSOR_ID_RV);
  SensorOrientation orientation(SENSOR_ID_ORI);
  
  String name = "Nicla-Mid_Back";

  void setup(){
    Serial.begin(115200);
    while (!Serial);

    Serial.println("Start");

    nicla::begin();
    nicla::leds.begin();
    nicla::leds.setColor(blue);

    //Sensors initialization
    BHY2.begin(NICLA_STANDALONE);
    gyroscope.begin();
    accelerometer.begin();
    quaternion.begin();
    orientation.begin();

    if (!BLE.begin()){
      Serial.println("Failed to initialized BLE!");

      while (1);
    }

    String address = BLE.address();

    Serial.print("address = ");
    Serial.println(address);

    address.toUpperCase();

    Serial.print("name = ");
    Serial.println(name);

    BLE.setLocalName(name.c_str());
    BLE.setDeviceName(name.c_str());
    BLE.setAdvertisedService(service);

    // Add all the previously defined Characteristics
   
    service.addCharacteristic(accelerometerCharacteristic);
    service.addCharacteristic(gyroscopeCharacteristic);
    service.addCharacteristic(quaternionCharacteristic);
    service.addCharacteristic(orientationCharacteristic);

    service.addCharacteristic(rgbLedCharacteristic);

    // Disconnect event handler
    BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

    rgbLedCharacteristic.setEventHandler(BLEWritten, onRgbLedCharacteristicWrite);


    BLE.addService(service);
    BLE.advertise();
  }

  void loop(){
    while (BLE.connected()){
      BHY2.update();
      nicla::leds.setColor(green);

      if (gyroscopeCharacteristic.subscribed()){
        float x, y, z;

        x = gyroscope.x();
        y = gyroscope.y();
        z = gyroscope.z();

        float gyroscopeValues[3] = {x, y, z};

        gyroscopeCharacteristic.writeValue(gyroscopeValues, sizeof(gyroscopeValues));
      }

      if (accelerometerCharacteristic.subscribed()){
        float x, y, z;
        x = accelerometer.x();
        y = accelerometer.y();
        z = accelerometer.z();

        float accelerometerValues[] = {x, y, z};
        accelerometerCharacteristic.writeValue(accelerometerValues, sizeof(accelerometerValues));
      }

      if(quaternionCharacteristic.subscribed()){
        float x, y, z, w;
        x = quaternion.x();
        y = quaternion.y();
        z = quaternion.z();
        w = quaternion.w();

        float quaternionValues[] = {x,y,z,w};
        quaternionCharacteristic.writeValue(quaternionValues, sizeof(quaternionValues));
      }

      if(orientationCharacteristic.subscribed()){
        float roll, pitch, yaw;
        roll = orientation.roll();
        pitch = orientation.pitch();
        yaw = orientation.heading();

        float orientationValues[] = {roll, pitch, yaw};
        orientationCharacteristic.writeValue(orientationValues, sizeof(orientationValues));
        delay(200)
;      }
    }
  }

  void blePeripheralDisconnectHandler(BLEDevice central){
    nicla::leds.setColor(red);
  }

  void onRgbLedCharacteristicWrite(BLEDevice central, BLECharacteristic characteristic){
    byte r = rgbLedCharacteristic[0];
    byte g = rgbLedCharacteristic[1];
    byte b = rgbLedCharacteristic[2];

    nicla::leds.setColor(r, g, b);
  }
