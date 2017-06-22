
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun19(t):
    return np.sqrt(2 * t + 3)

x1 = np.linspace(-10,10,100)

y1 = fun19(x1)

plt.plot(x1,y1)
plt.show()