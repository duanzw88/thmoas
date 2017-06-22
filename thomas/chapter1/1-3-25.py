#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun25(x):
    return 1.0 / (x - 1)

x1 = np.linspace(1.1,10,100)
y1 = fun25(x1)
x2 = np.linspace(-10,0.9,100)
y2 = fun25(x2)

Y=np.linspace(-10,10,100)
X=np.ones(Y.size)

plt.plot(x1,y1,'r',x2,y2,'g',X,Y,'r-*')
plt.ylim(-10,10)
plt.xlim(-3,5)
plt.show()