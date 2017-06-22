
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_45(x):
    return  x ** 3 + 2 * x


x1 = np.linspace(-0.5,3,100)
y1 = fun5_45(x1)

plt.plot(x1,y1,'r')
plt.xlim(-2,5)
plt.ylim(-10,10)
plt.show()