import serial
import time
import csv

ser = serial.Serial("/dev/ttyUSB0", 9600)

X = [0] * 3
C =  [0] * 3
signalX = ""
signalC = 0

if(ser.isOpen()):
    while 1:
        if(ser.inWaiting() > 0):
            aux = ser.read()
            print(aux)
            if (aux == '*'):
                print("signal")
                print(signalX)
                print(len(signalX))
                print(float(signalX))
                X.pop(0)
                X.append(float(signalX))
                print(X)
                C.pop(0)
                C.append(float(signalC))
                signalC = 1.6016*(10**-7)*X[0] + 6.15632*(10**-7)*X[1] + 1.47847*(10**-7)*X[2] - (2.84662*C[0] + 2.698752*C[1] - 0.852144*C[2])
                
                print(signalC)
                signalC = format(signalC, '.10f')

                ser.write('B')

                for i in range(len(signalC)):
                    ser.write(signalC[i])
                    time.sleep(0.01)

                ser.write('C')

                with open("test_data.csv","a") as f :
                    writer = csv.writer(f , delimiter ="," )
                    writer.writerow([str(signalC)])

                signalX = ""
                print("debug")
                print(signalX)
                print("debug")

            else:
                signalX += aux



else:
    print("error")

