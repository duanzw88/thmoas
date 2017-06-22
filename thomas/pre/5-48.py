#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-10,10,0.1)
y1 = 4 * x / (x ** 2 + 1)
y2 = 2 * np.sin(2 * np.arctan(x))
plt.xlim(-10,10)
plt.ylim(-5,20)
plt.plot(x,y1,c='r',label="4x/(x*x+1)")
# plt.plot(x,y2,c='b',label="2sin(2arctan(x))")
plt.legend()
plt.show()