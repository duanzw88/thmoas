#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x,a,b):
    return a * np.exp(-x * b)
x = np.array([0,1,2,3,4,5,6,7,8])
y = np.array([0.500,0.345,0.238,0.164,0.113,0.078,0.054,0.037,0.026])

plt.scatter(x,y)
#幂函数预测
ppot,pcov = curve_fit(func,x,y)
print "ppot = ",ppot

x1 = np.arange(0.1,10,0.01)
y1 = func(x1,ppot[0],ppot[1])
plt.plot(x1,y1,c='r')

y12 = func(12,ppot[0],ppot[1])
print "y12 = ",y12
plt.show()