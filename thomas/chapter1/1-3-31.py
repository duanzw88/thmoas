#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun31(x):
    return ((x ** 2) - x + 1) / (x - 1)

x1 = np.linspace(-10,0.99,100)
y1 = fun31(x1)

x2 = np.linspace(1.01,10,100)
y2 = fun31(x2)


Y=np.linspace(-10,10,100)
X=np.ones(Y.size)

plt.plot(x1,y1,'g',x2,y2,'g',X,Y,'r-')
plt.ylim(-10,10)
plt.xlim(-3,5)
plt.show()