import numpy as np
import matplotlib.pyplot as plt

def fun59(x):
    return - (x ** 2 - 4) / (x + 1)

x1 = np.linspace(-10,-1.01,100)
y1 = fun59(x1)

x2 = np.linspace(1.01,10,100)
y2 = fun59(x2)

x3 = np.linspace(-8,8,100)
y3 = 1 - x3

y4 = np.linspace(-8,8,16)
x4 = np.zeros(y4.size) - 1

plt.plot(x1,y1,x2,y2)
plt.plot(x3,y3,'r',x4,y4,'r')
plt.xlim(-10,10)
plt.ylim(-8,8)
plt.show()