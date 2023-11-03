#include <ArduinoBLE.h>
#include <Arduino.h>
#include "Arduino_BHY2.h"
#include "Nicla_System.h"

BLEService IMU_service("1DEF87B3-2E28-F599-8576-74A3B9D3A0E3");

BLECharacteristic accelerometerCharacteristic("e1c15689-9ccf-4d02-b051-1101ef587b01", BLERead | BLENotify, 3 * sizeof(float));  // Array of 3x 2 Bytes, XY
BLECharacteristic gyroscopeCharacteristic("e1c15689-9ccf-4d02-b051-1101ef587b02", BLERead | BLENotify, 3 * sizeof(float));    // Array of 3x 2 Bytes, XYZ
BLECharacteristic rgbLedCharacteristic("e1c15689-9ccf-4d02-b051-1101ef587b03", BLERead | BLEWrite, 3 * sizeof(byte));

SensorXYZ gyroscope(SENSOR_ID_GYRO);
SensorXYZ accelerometer(SENSOR_ID_ACC);


void setup() {
  Serial.begin(9600);
  while (!Serial);  // wait for serial monitor to open
  Serial.println("Setup started");
  
  BHY2.begin();
  accelerometer.begin();
  gyroscope.begin();

  nicla::begin();
  nicla::leds.begin();
  nicla::leds.setColor(red);

  
  // begin initialization
  if (!BLE.begin()) 
  {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  
  String address = BLE.address();
  Serial.print("BLE address of this device is: ");
  Serial.println(address);

  BLE.setLocalName("Right_Knee");
  BLE.setAdvertisedService(IMU_service);
  
  IMU_service.addCharacteristic(accelerometerCharacteristic);
  IMU_service.addCharacteristic(gyroscopeCharacteristic);
  IMU_service.addCharacteristic(rgbLedCharacteristic);

  BLE.addService(IMU_service);

  BLE.advertise();
}

void loop() 
{
  // while (BLE.connected())
  // {
  //   nicla::leds.setColor(green);
  //   static auto lastCheck = millis();

  //   // Update function should be continuously polled
  //   BHY2.update();

  //   // Check sensor values every second  
  //   if (millis() - lastCheck >= 1000) 
  //   {
  //     lastCheck = millis();
      
  //     float accData[3] = {accelerometer.x(), accelerometer.y(), accelerometer.z()};
  //     float gyroData[3] = {gyroscope.x(), gyroscope.y(), gyroscope.z()};
      
  //     accelerometerCharacteristic.writeValue(accData, 3 * sizeof(float));
  //     gyroscopeCharacteristic.writeValue(gyroData, 3 * sizeof(float));
  //   }
  // }
  // nicla::leds.setColor(red);

  if (BLE.connected())
  {
    nicla::leds.setColor(green);
    delay(1500);
  }
  if (!BLE.connected())
  {
    nicla::leds.setColor(red);
    delay(1500);
  }
}
