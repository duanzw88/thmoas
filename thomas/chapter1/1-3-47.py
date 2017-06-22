#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun47(x):
    return x / np.sqrt(4 - x ** 2)

x1 = np.linspace(-10,-2.01,100)
y1 = fun47(x1)

x2 = np.linspace(-1.99,1.99,100)
y2 = fun47(x2)

x3 = np.linspace(2.01,10,100)
y3 = fun47(x3)


plt.plot(x1,y1,x2,y2,x3,y3)
plt.xlim(-5,5)
plt.show()