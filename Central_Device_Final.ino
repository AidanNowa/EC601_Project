#include <ArduinoBLE.h>

#define NUM_PERIPHERALS 2
#define BLE_PERIPHERALS(sensor_prefix, char_val) (sensor_prefix "b10000-" char_val "-537e-4f6c-d104768a1214")

BLEDevice peripherals[NUM_PERIPHERALS];
int connectedDevices = 0;

const char* L_ankle_peripheralServiceUUID = BLE_PERIPHERALS("19", "0000");
const char* L_ankle_quaternionCharacteristicUuid = BLE_PERIPHERALS("19", "1000");
const char* L_ankle_rbgLedCharacteristicUuid = BLE_PERIPHERALS("19", "2000");

const char* R_ankle_peripheralServiceUUID = BLE_PERIPHERALS("20", "0000");
const char* R_ankle_quaternionCharacteristicUuid = BLE_PERIPHERALS("20", "1000");
const char* R_ankle_rbgLedCharacteristicUuid = BLE_PERIPHERALS("20", "2000");

const char* L_shank_peripheralServiceUUID = BLE_PERIPHERALS("21", "0000");
const char* L_shank_quaternionCharacteristicUuid = BLE_PERIPHERALS("21", "1000");
const char* L_shank_rbgLedCharacteristicUuid = BLE_PERIPHERALS("21", "2000");

const char* R_shank_peripheralServiceUUID = BLE_PERIPHERALS("22", "0000");
const char* R_shank_quaternionCharacteristicUuid = BLE_PERIPHERALS("22", "1000");
const char* R_shank_rbgLedCharacteristicUuid = BLE_PERIPHERALS("22", "2000");

const char* L_femur_peripheralServiceUUID = BLE_PERIPHERALS("23", "0000");
const char* L_femur_quaternionCharacteristicUuid = BLE_PERIPHERALS("23", "1000");
const char* L_femur_rbgLedCharacteristicUuid = BLE_PERIPHERALS("23", "2000");

const char* R_femur_peripheralServiceUUID = BLE_PERIPHERALS("24", "0000");
const char* R_femur_quaternionCharacteristicUuid = BLE_PERIPHERALS("24", "1000");
const char* R_femur_rbgLedCharacteristicUuid = BLE_PERIPHERALS("24", "2000");

const char* sacrum_peripheralServiceUUID = BLE_PERIPHERALS("25", "0000");
const char* sacrum_quaternionCharacteristicUuid = BLE_PERIPHERALS("25", "1000");
const char* sacrum_rbgLedCharacteristicUuid = BLE_PERIPHERALS("25", "2000");

const char* lumbar_peripheralServiceUUID = BLE_PERIPHERALS("26", "0000");
const char* lumbar_quaternionCharacteristicUuid = BLE_PERIPHERALS("26", "1000");
const char* lumbar_rbgLedCharacteristicUuid = BLE_PERIPHERALS("26", "2000");

const char* thoracic_peripheralServiceUUID = BLE_PERIPHERALS("27", "0000");
const char* thoracic_quaternionCharacteristicUuid = BLE_PERIPHERALS("27", "1000");
const char* thoracic_rbgLedCharacteristicUuid = BLE_PERIPHERALS("27", "2000");

const char* cervival_peripheralServiceUUID = BLE_PERIPHERALS("28", "0000");
const char* cervical_quaternionCharacteristicUuid = BLE_PERIPHERALS("28", "1000");
const char* cervical_rbgLedCharacteristicUuid = BLE_PERIPHERALS("28", "2000");

const char* sternum_peripheralServiceUUID = BLE_PERIPHERALS("29", "0000");
const char* sternum_quaternionCharacteristicUuid = BLE_PERIPHERALS("29", "1000");
const char* sternum_rbgLedCharacteristicUuid = BLE_PERIPHERALS("29", "2000");

const char** serviceUUID_array = new const char*[NUM_PERIPHERALS];


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
  //Serial.println("in main loop..");
  connectToPeripherals();
}
void connectToPeripherals(){
  //Serial.println("in coonectToPeripherals func..");
  serviceUUID_array[0] = L_ankle_peripheralServiceUUID;
  serviceUUID_array[1] = R_ankle_peripheralServiceUUID;
  serviceUUID_array[2] = L_shank_peripheralServiceUUID;
  serviceUUID_array[3] = R_shank_peripheralServiceUUID;
  serviceUUID_array[4] = L_femur_peripheralServiceUUID;
  serviceUUID_array[5] = R_femur_peripheralServiceUUID;
  serviceUUID_array[6] = sacrum_peripheralServiceUUID;
  serviceUUID_array[7] = lumbar_peripheralServiceUUID;
  serviceUUID_array[8] = thoracic_peripheralServiceUUID;
  serviceUUID_array[9] = cervival_peripheralServiceUUID;
  serviceUUID_array[10] = sternum_peripheralServiceUUID;

  //Serial.println(serviceUUID_array[0]);
  bool flag = false;

  do{
    for (int i=0; i<NUM_PERIPHERALS; i++)
    {
      flag = false;
      BLE.scanForUuid(serviceUUID_array[i]);
      delay(500);
      peripherals[i] = BLE.available();
      delay(500);
      if (!peripherals[i]){
        flag=true;
        Serial.print("Error scanning for sensor: "); Serial.println(i);
        i = 0;
      }
    }
  } while(flag);

  Serial.println("Checking connection..");
  if (!checkConnection());{
    return;
  }
  
  readData();

}


bool checkConnection(){
  for (int i=0; i>NUM_PERIPHERALS; i++)
    {
      if (!peripherals[i].connect()){
        Serial.println("Error Connecting to Peripherals, re-trying...");
        return 0;
      }
      if (!peripherals[i].discoverAttributes()){
        Serial.println("Error Discovering Attributes, re-trying...");
        return 0;
      }
    }
  
  Serial.println("Connected to Sensors!");
  
  for (int i=0; i>NUM_PERIPHERALS; i++)
  {
    Serial.print("Sensor "); Serial.print(i); Serial.print(": ");
    Serial.println(peripherals[i].localName());
  }
  return 1;
}

void readData(){

  BLECharacteristic L_ankle_quaternionCharacteristic = peripherals[0].characteristic(L_ankle_quaternionCharacteristicUuid);
  if(L_ankle_quaternionCharacteristic.subscribed()){
    connected_devices++;
  }
  BLECharacteristic L_ankle_rbgLedCharacteristic = peripherals[0].characteristic(L_ankle_rbgLedCharacteristicUuid);

  BLECharacteristic R_ankle_quaternionCharacteristic = peripherals[1].characteristic(R_ankle_quaternionCharacteristicUuid);
  if(R_ankle_quaternionCharacteristic.subscribed()){
    connected_devices++;
  }
  BLECharacteristic R_ankle_rbgLedCharacteristic = peripherals[1].characteristic(R_ankle_rbgLedCharacteristicUuid);

  BLECharacteristic L_shank_quaternionCharacteristic = peripherals[3].characteristic(L_shank_quaternionCharacteristicUuid);
  BLECharacteristic L_shank_rbgLedCharacteristic = peripherals[3].characteristic(L_shank_rbgLedCharacteristicUuid);

  BLECharacteristic R_shank_quaternionCharacteristic = peripherals[4].characteristic(R_shank_quaternionCharacteristicUuid);
  BLECharacteristic R_shank_rbgLedCharacteristic = peripherals[4].characteristic(R_shank_rbgLedCharacteristicUuid);

  BLECharacteristic L_femur_quaternionCharacteristic = peripherals[5].characteristic(L_femur_quaternionCharacteristicUuid);
  BLECharacteristic L_femur_rbgLedCharacteristic = peripherals[5].characteristic(L_femur_rbgLedCharacteristicUuid);

  BLECharacteristic R_femur_quaternionCharacteristic = peripherals[6].characteristic(R_femur_quaternionCharacteristicUuid);
  BLECharacteristic R_femur_rbgLedCharacteristic = peripherals[6].characteristic(R_femur_rbgLedCharacteristicUuid);

  BLECharacteristic sacrum_quaternionCharacteristic = peripherals[7].characteristic(sacrum_quaternionCharacteristicUuid);
  BLECharacteristic sacrum_rbgLedCharacteristic = peripherals[7].characteristic(sacrum_rbgLedCharacteristicUuid);
 
  BLECharacteristic lumbar_quaternionCharacteristic = peripherals[8].characteristic(lumbar_quaternionCharacteristicUuid);
  BLECharacteristic lumbar_rbgLedCharacteristic = peripherals[8].characteristic(lumbar_rbgLedCharacteristicUuid);

  BLECharacteristic thoracic_quaternionCharacteristic = peripherals[9].characteristic(thoracic_quaternionCharacteristicUuid);
  BLECharacteristic thoracic_rbgLedCharacteristic = peripherals[9].characteristic(thoracic_rbgLedCharacteristicUuid);

  BLECharacteristic cervical_quaternionCharacteristic = peripherals[10].characteristic(cervical_quaternionCharacteristicUuid);
  BLECharacteristic cervical_rbgLedCharacteristic = peripherals[10].characteristic(cervical_rbgLedCharacteristicUuid);

  BLECharacteristic sternum_quaternionCharacteristic = peripherals[10].characteristic(sternum_quaternionCharacteristicUuid);
  BLECharacteristic sternum_rbgLedCharacteristic = peripherals[10].characteristic(sternum_rbgLedCharacteristicUuid);

  bool flag = true;

  do{
    for (int i=0; i<NUM_PERIPHERALS; i++)
    {
      if (peripherals[i].connected){
        flag = true;
      }
      else{
        flag = false;
      }
    }
    
  //code to read characteristcs and print to serial monitor (format like sample .sto)

  } while(flag);

}
