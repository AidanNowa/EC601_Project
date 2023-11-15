import asyncio
from bleak import BleakClient
import csv
import struct

## still need to debug this script, cant connect to the board still

# Replace with your Nicla's BLE address
address = "ad:2e:11:26:10:f8"

# BLE UUIDs from your Arduino sketch
accelerometer_uuid = "e1c15689-9ccf-4d02-b051-1101ef587b01"
gyroscope_uuid = "e1c15689-9ccf-4d02-b051-1101ef587b02"


async def read_characteristics(client):
    with open('IMU_data.csv', mode='w', newline='') as file: 
        writer = csv.writer(file)                               # write IMU data to csv
        writer.writerow(["Ax", "Ay", "Az", "Gx", "Gy", "Gz"])  # write header
        
        while True:
            acc_data = await client.read_gatt_char(accelerometer_uuid)  #read IMU data advertized by peripheral 
            gyro_data = await client.read_gatt_char(gyroscope_uuid)
            
            acc_values = struct.unpack('fff', bytes(acc_data))
            gyro_values = struct.unpack('fff', bytes(gyro_data))
            
            writer.writerow(acc_values + gyro_values)
            await asyncio.sleep(1)  # Adjust the delay as needed

async def main():
    async with BleakClient(address) as client:
        # await discover_characteristics(client)  # Optional: to browse services and characteristics
        await read_characteristics(client)

loop = asyncio.get_event_loop()
loop.run_until_complete(main())
