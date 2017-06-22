import numpy as np
import matplotlib.pyplot as plt

def fun63(x):
    return 3.0 / 2.0 * np.power((x - 1.0 / x),2.0/3.0)

x1 = np.linspace(-10,-1.01,100)
y1 = fun63(x1)

x2 = np.linspace(-0.99,-0.01,100)
y2 = fun63(x2)


x3 = np.linspace(0.01,0.99,100)
y3 = fun63(x3)

x4 = np.linspace(1.01,10,100)
y4 = fun63(x2)

plt.plot(x1,y1,x2,y2)
plt.plot(x3,y3,'r-',x4,y4)
plt.xlim(-10,10)
plt.ylim(-8,8)
plt.show()