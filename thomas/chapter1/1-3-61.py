import numpy as np
import matplotlib.pyplot as plt

def fun61(x):
    return x ** 3 +  3 / x

x1 = np.linspace(-10,-0.01,100)
y1 = fun61(x1)

x2 = np.linspace(0.01,10,100)
y2 = fun61(x2)

x3 = np.linspace(-8,8,100)
y3 = x3 ** 3

x4 = np.linspace(-8,-0.01,100)
y4 = 3 / x4
x5 = np.linspace(0.01,8,100)
y5 = 3 / x5

plt.plot(x1,y1,x2,y2)
plt.plot(x3,y3,'r--',x4,y4,'r--',x5,y5,'r--')
plt.xlim(-10,10)
plt.ylim(-8,8)
plt.show()