
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_25(x):
    if(x.all() == 0):
        return 0
    else:
        return x ** 2 * np.sin(1.0 / x)

x1 = np.linspace(-2,2,1000)

y1 = fun5_25(x1)

plt.plot(x1,y1)
plt.xlim(-2,2)
plt.ylim(-2,2)
plt.show()