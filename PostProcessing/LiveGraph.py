import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import serial

style.use('seaborn-whitegrid')
fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)
plt.subplots_adjust(left=0.12, bottom=0.10, right=0.95, top=0.90, wspace=0.20, hspace=0)

serialArduino = serial.Serial('/dev/cu.usbmodem1411',9600,timeout=0)
    
def animate(i):
    #graph_data = open('example.txt','r').read()
    graph_data = serialArduino.readline().decode('utf-8')
    lines = graph_data.split('\n')
    xs = []
    ys = []
    for line in lines:
        if len(line) > 1:
            x, y = line.split(',')
            xs.append(x)
            ys.append(y)
    ax1.clear()
    ax1.plot(xs, ys, linewidth=1)
    ax1.set_xlabel('Velocity in./sec)')
    ax1.set_ylabel('Force (lbs)')
    ax1.set_title('Force vs. Velocity')
    
ani = animation.FuncAnimation(fig, animate, interval=1000)
plt.show()