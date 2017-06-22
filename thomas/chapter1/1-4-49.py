
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun47(x):
    return np.sqrt(x) + np.sqrt(x + 1) - 4

x1 = np.linspace(0,5,100)

y1 = fun47(x1)

plt.plot(x1,y1)
plt.xlim(-5,5)
# plt.ylim(-5,5)
plt.show()