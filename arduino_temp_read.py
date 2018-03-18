#This short python script uses the Pyserial library to connect
#to an Arduino on COM3 and reads the output from the Arduino sketch
import serial

arduino = serial.Serial("COM3", 9600)   

datas = arduino.readline()
output = datas.decode('utf8')
print (output)

arduino.close()