import serial
import datetime
import time
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import style

dt_now = datetime.datetime.now()
file_name = 'RunTime' + str(dt_now) + '.txt' 
#serial_Arduino = serial.Serial('/dev/cu.usbmodem1411',9600,timeout=0)

with open (file_name, 'w') as newfile:
    pass
#    ARDData = serial_Arduino.readline().decode('utf-8')
#    newfile.write(ARDData)

start_time = time.time()
elapsed_time = 0

serial_Arduino = serial.Serial('/dev/cu.usbmodem1411',115200,timeout=0)
while (elapsed_time < 10):
    with open (file_name, 'a') as appendFile:
        Arduino_info = serial_Arduino.readline().decode('utf-8')
        appendFile.write(Arduino_info)
        elapsed_time = time.time() - start_time

style.use('seaborn-whitegrid')
x,y = np.loadtxt(file_name, unpack = True, delimiter = ', ')
plt.plot(x,y)
plt.title('Force vs. Velocity')
plt.ylabel('Force(lbs)')
plt.xlabel('Velocity(in./sec)')
plt.show()