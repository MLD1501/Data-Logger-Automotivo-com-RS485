import serial
import csv

sensor_data = []
line = 0
mySerial = serial.Serial("COM4", 57600)
file = open("Data","a")
print("Create File")

#Lendo serial e gravando  dados em array
while line <= 4000:
    mySerial.flush()
    getData = mySerial.readline()
    dataString = getData.decode('utf-8')
    data = dataString[0:][:-2]
    print(data)
    readings = data.split(",")
    print(readings)
    sensor_data.append(readings)
    print(sensor_data)
    line = line+1

print(sensor_data)

#Salvando array em bloco de notas
with open("Data", 'w', encoding='UTF8', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(sensor_data)
print("Data collection complete!")
file.close()

