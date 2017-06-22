
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_35(x):
    return np.power(x**2,1.0/5.0)

x1 = np.linspace(-5,5,100)

y1 = fun5_35(x1)

plt.plot(x1,y1)
plt.xlim(-5,5)
plt.ylim(0,10)
plt.show()