# -*- conding:utf-8 -*-
#
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-100,100,1)
y1 = (9.0 / 5.0) *(x) + 32
y2 = (5.0 / 9.0) * (x - 32)
y3 = x

plt.plot(x,y1)
plt.plot(x,y2)
plt.plot(x,y3)
plt.show()