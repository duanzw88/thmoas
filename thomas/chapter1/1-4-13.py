
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun13(x):
    return  1 / (x - 2) - 3 * x

x1 = np.linspace(-10,1.99,100)
y1 = fun13(x1)

x2 = np.linspace(2.01,10,100)
y2 = fun13(x2)

plt.plot(x1,y1,x2,y2)
plt.show()