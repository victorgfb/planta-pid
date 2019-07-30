import serial
import time

ser = serial.Serial("/dev/ttyUSB0", 9600)

X = [0] * 3
C =  [0] * 3
signalX = ""
signalC = 0

if(ser.isOpen()):
    while 1:
        if(ser.inWaiting() > 0):
            aux = ser.read().decode()

            if aux == "\0":
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
                
                #problemas para truncar o sinal de saida C
                
                print(signalC)
                signalC = format(signalC, '.10f')
                print(signalC)
                byteAr = bytearray(str(signalC), 'utf-8')

                print(byteAr)
                for byte in byteAr:
                    print(chr(byte))
                    ser.write(byte)
                
                signalX = ""

            else:
                signalX += aux



else:
    print("error")

