
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun21(x):
    return np.sin(x - np.sin(x))

x1 = np.linspace(-5,5,100)

y1 = fun21(x1)

plt.plot(x1,y1)
plt.show()