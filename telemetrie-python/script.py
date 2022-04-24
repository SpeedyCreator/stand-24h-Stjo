import serial
import time

ser = serial.Serial('/dev/ttyUSB0',9600,timeout=1)
#ser.open()

try:
   serial_data = ser.readline()
   print (serial_data)
except serial.serialutil.SerialException:
   pass