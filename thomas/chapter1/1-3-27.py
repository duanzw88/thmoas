#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun27(x):
    return (2 * (x ** 2) + x -1) / ((x ** 2) - 1)

x1 = np.linspace(-10,-1.01,100)
y1 = fun27(x1)

x2 = np.linspace(-0.99,0.99,100)
y2 = fun27(x2)

x3 = np.linspace(1.01,10,100)
y3 = fun27(x3)

Y=np.linspace(-10,10,100)
X=np.ones(Y.size)

plt.plot(x1,y1,'r',x2,y2,'g',x3,y3,'b',X,Y,'r-*')
plt.ylim(-10,10)
plt.xlim(-3,5)
plt.show()