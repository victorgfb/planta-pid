import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import numpy as np
import csv

style.use('fivethirtyeight')

class anima:
    def __init__(self):
        fig = plt.figure()
        self.ax1 = fig.add_subplot(1,1,1)
        self.ani = animation.FuncAnimation(fig, self.animate, interval = 500)
        plt.show()
    
    def animate(self, i):
        self.xs = np.array(0)
        self.ys = np.array(0)

        with open('data.csv') as csvfile:
            readCSV = csv.reader(csvfile, delimiter=',')
            count = 0
            for row in readCSV:
                self.xs = np.append(self.xs, count * 0.01)
                count += 1
                self.ys = np.append(self.ys, float(row[0]))

        self.ax1.clear()
        self.ax1.plot(self.xs, self.ys)
        
anim = anima()