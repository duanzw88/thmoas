
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun15(t):
    return  (t + 1.0) / (t ** 2 - 4 * t + 3.0)

x1 = np.linspace(-10,0.99,100)
x2 = np.linspace(1.01,2.99,100)
x3 = np.linspace(3.01,10,100)

y1 = fun15(x1)
y2 = fun15(x2)
y3 = fun15(x3)

plt.plot(x1,y1,x2,y2,x3,y3)
plt.show()