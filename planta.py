import serial
import time
import csv
import os

ser = serial.Serial("/dev/ttyUSB0", 9600)

X = [0] * 3
C =  [0] * 3
signalX = ""
signalC = 0

if(os.path.isfile('data.csv')):
    os.remove("data.csv")

if(ser.isOpen()):
    while 1:
        if(ser.inWaiting() > 0):
            aux = ser.read().decode()
            if (aux == '*'):
                X.pop()
                X.insert(0,float(signalX))
                C.pop()
                C.insert(0,float(signalC))
                signalC = 1.6016*(10**-7)*X[0] + 6.15632*(10**-7)*X[1] + 1.47847*(10**-7)*X[2] - (-2.84662*C[0] + 2.698752*C[1] - 0.852144*C[2])
                
                signalC = format(signalC, '.10f')
    
                ser.write('B')

                for i in range(len(signalC)):
                    ser.write(signalC[i])

                ser.write('C')

                with open("data.csv","a") as f :
                    writer = csv.writer(f , delimiter ="," )
                    writer.writerow([str(signalC)])

                signalX = ""

            else:
                signalX += aux

else:
    print("error")

