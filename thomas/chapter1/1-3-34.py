#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun34(x):
    return (4 * x) / ((x ** 2) + 4)

x1 = np.linspace(-10,10,100)
y1 = fun34(x1)



Y=np.linspace(-10,10,100)
X=np.zeros(Y.size)

plt.plot(x1,y1,'g',X,Y,'r-')
plt.ylim(-2,3)
plt.xlim(-3,5)
plt.show()