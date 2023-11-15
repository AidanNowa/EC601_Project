import serial
import csv
import time

# Connect to serial port
ser = serial.Serial('COM_PORT', 9600)  # Replace 'COM_PORT' with your actual COM port

# Open the CSV file
with open('imu_data.txt', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Timestamp", "IMU Data"])  # Write the header row
    
    while True:
        if ser.inWaiting() > 0:
            line = ser.readline().decode('utf-8').rstrip()
            writer.writerow([time.time(), line])