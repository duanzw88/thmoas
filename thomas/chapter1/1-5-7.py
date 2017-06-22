
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_7(x):
    return x ** 3

x1 = np.linspace(-5,5,100)

y1 = fun5_7(x1)
y2 = 12 * x1 + 16

plt.plot(x1,y1,x1,y2)
plt.xlim(-5,5)
# plt.ylim(-5,5)
plt.show()