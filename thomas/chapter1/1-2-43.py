#-*- coding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

def fun(x):
    if(np.all(x) == 0):
        return 0
    return x * np.sin(1/x)
def fun2(x):
    if(np.all(x) == 0):
        return 0
    return np.sin(1/x)

x = np.arange(-1,1,0.001)
y = fun(x)
y2 = fun2(x)
plt.plot(x,y,c='red')
plt.plot(x,y2,c='blue')
plt.show()

