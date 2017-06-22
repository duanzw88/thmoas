
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun17(t):
    return np.cos(t) / t

x1 = np.linspace(-2,-0.01,100)
x2 = np.linspace(0.01,2,100)

y1 = fun17(x1)
y2 = fun17(x2)

plt.plot(x1,y1,x2,y2)
plt.show()