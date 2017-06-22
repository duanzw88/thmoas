#-*- coding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

def fun1(x):
    if(np.all(x) != 0):
        return np.pi - (2 / np.power(x,2))
    else:
        return 0
def fun2(x):
    if(np.all(x) != 0):
        return (-5 + (7 / x)) / (3 - (1 / np.power(x,2)))
    else:
        return 0

x = np.arange(-2,2,0.01)
y = fun1(x)
# y2 = fun2(x)

plt.plot(x,y,c='red')
# plt.plot(x,y2,c='blue')
plt.show()