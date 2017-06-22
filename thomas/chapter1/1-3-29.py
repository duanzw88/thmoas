#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun29(x):
    return ((x ** 4) + 1) / (x ** 2)

x1 = np.linspace(-10,-0.01,100)
y1 = fun29(x1)

x2 = np.linspace(0.01,10,100)
y2 = fun29(x2)


Y=np.linspace(-10,10,100)
X=np.zeros(Y.size)

plt.plot(x1,y1,'r',x2,y2,'g',X,Y,'r-')
plt.ylim(-10,10)
plt.xlim(-3,5)
plt.show()