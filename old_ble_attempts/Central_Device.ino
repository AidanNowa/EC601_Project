#include <ArduinoBLE.h>
#include <Arduino.h>


void setup() {
  Serial.begin(9600);
  while (!Serial);  // wait for serial monitor to open
  Serial.println("Setup started");

  if (!BLE.begin()) 
  {
    Serial.println("Starting BLE failed!");
    while (1);
  }
  
  digitalWrite(LEDR, LOW); //Red

  
  BLE.scanForAddress("61:2d:cb:78:55:e9");

}

void loop() {
  // Check for BLE devices
  
  BLEDevice peripheral = BLE.available();

  if (peripheral)
  {
    Serial.println("Connecting ...");
    if (peripheral.connect())
    {
      Serial.println("Connected!");
      
      //for developing purposes: make sure correct UUID service is being advertized
      if (peripheral.hasAdvertisedServiceUuid()) 
      {
        Serial.print("Service UUIDs: ");
        for (int i = 0; i < peripheral.advertisedServiceUuidCount(); i++)
        { 
          Serial.print(peripheral.advertisedServiceUuid(i));
          Serial.print(" ");
        }
      }
      while(peripheral.connect())
      {
        //Code for reading IMU charactertisitcs here:

        //debugging to see if charactersitics are being advertized
        // if (R_Knee_IMU_Service.hasCharacteristic("2b15"))
        // {
        // Serial.println("Accelerometer Characteristic found!");
        // } 
      }
      Serial.println("Disconnected!");
    }
    else
    {
    //try scanning again and loop again if connection failed
    BLE.scanForAddress("61:2d:cb:78:55:e9");
    }
  }
} 

