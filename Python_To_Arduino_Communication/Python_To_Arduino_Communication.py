#!/usr/bin/python
import serial
ser = serial.Serial('COM9', 9600)
ser.write(b'5~')
ser.close()

