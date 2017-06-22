#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

t = np.arange(-np.pi / 2,np.pi / 2,0.01*np.pi)
x = 1 / np.cos(t)
y = 1 * np.tan(t)
plt.xlim(-10,10)
plt.ylim(-10,10)
x2 = 2 / np.cos(t)
y2 = 2 * np.tan(t)

x3 = 3 / np.cos(t)
y3 = 3 * np.tan(t)
plt.plot(x,y,c='r')
plt.plot(x2,y2,c='g')
plt.plot(x3,y3,c='b')
plt.show()