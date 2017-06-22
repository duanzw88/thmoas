#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun49(x):
    return np.power(x,2.0/3.0) + 1 / np.power(x,1.0/3.0)

x1 = np.linspace(-5,-0.01,1000)
y1 = fun49(x1)

x2 = np.linspace(0.01,5,1000)
y2 = fun49(x2)


print np.power(1,2.0/3.0)

plt.plot(x1,y1,x2,y2)
plt.xlim(-5,5)
plt.ylim(-8,8)
plt.show()