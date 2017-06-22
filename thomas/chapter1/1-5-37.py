
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_37(x):
    return np.power(x,0.2)

x1 = np.linspace(-5,-1,100)
y1 = fun5_37(x1)

plt.plot(x1,y1,'r')
plt.xlim(-5,5)
plt.ylim(-10,10)
plt.show()