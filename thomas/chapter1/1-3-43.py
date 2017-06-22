#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def fun43(x):
    return np.sqrt(x ** 2 + x + 1) - x

x = np.linspace(1,100,1000)
y = fun43(x)


plt.plot(x,y,'g')
plt.show()