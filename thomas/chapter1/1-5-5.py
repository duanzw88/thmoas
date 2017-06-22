
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_1(x):
    return 4 - x ** 2

x1 = np.linspace(-5,5,100)

y1 = fun5_1(x1)
y2 = 2 * x1 + 5

plt.plot(x1,y1,x1,y2)
plt.xlim(-5,5)
# plt.ylim(-5,5)
plt.show()