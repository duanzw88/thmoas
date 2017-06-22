
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun41(x):
    return x **3  - 3 * x - 1

x1 = np.linspace(-5,5,100)

y1 = fun41(x1)

plt.plot(x1,y1)
plt.xlim(-2,2)
plt.ylim(-5,5)
plt.show()