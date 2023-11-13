#include <ArduinoBLE.h>
#include <Arduino.h>
#include "Arduino_BHY2.h"
#include "Nicla_System.h"

BLEService IMU_service("2a14");

BLECharacteristic accelerometerCharacteristic("2b15", BLERead | BLENotify, 3 * sizeof(float));  // Array of 3x 2 Bytes, XY
BLECharacteristic gyroscopeCharacteristic("2c16", BLERead | BLENotify, 3 * sizeof(float));    // Array of 3x 2 Bytes, XYZ
BLECharacteristic rgbLedCharacteristic("2d17", BLERead | BLEWrite, 3 * sizeof(byte));

SensorXYZ gyroscope(SENSOR_ID_GYRO);
SensorXYZ accelerometer(SENSOR_ID_ACC);


void setup() {
  //startup
  Serial.begin(9600);
  while (!Serial);  // wait for serial monitor to open
  Serial.println("Setup started");
  
  //initialize sensors and nicla board
  if (!BHY2.begin()) 
  {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  accelerometer.begin();
  gyroscope.begin();

  nicla::begin();
  nicla::leds.begin();
  nicla::leds.setColor(red);
  ///
  //Check UUIDs of service and charactertistics (debugging purposes)
  Serial.print("IMU service UUID = ");
  Serial.println(IMU_service.uuid());
  Serial.print("Accelerometer characteristic UUID = ");
  Serial.println(accelerometerCharacteristic.uuid());
  
  // begin initialization
  if (!BLE.begin()) 
  {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  //check BLE address (debugging purposes)
  String address = BLE.address();
  Serial.print("BLE address of this device is: ");
  Serial.println(address);

  //set name and advertising service (associate w/ joint)
  BLE.setLocalName("R_Knee");
  BLE.setDeviceName("R_Knee");
  BLE.setAdvertisedService(IMU_service);
  
  IMU_service.addCharacteristic(accelerometerCharacteristic);
  IMU_service.addCharacteristic(gyroscopeCharacteristic);
  IMU_service.addCharacteristic(rgbLedCharacteristic);

  BLE.addService(IMU_service);
  
  //begin advertising
  BLE.advertise();
  Serial.println("BLE IMU Peripheral advertising...");
}

void loop() 
{
  while (BLE.connected())
  {
    nicla::leds.setColor(green);
    // Update function should be continuously polled
    BHY2.update();

    float x, y, z;
    x = accelerometer.x();
    y = accelerometer.y();
    z = accelerometer.z();

    float accelerometerValues[] = {x, y, z};
    accelerometerCharacteristic.writeValue(accelerometerValues, sizeof(accelerometerValues));
    delay(1500);
  }

  if (!BLE.connected())
  {
    nicla::leds.setColor(red);
    delay(1500);
  }
}

