#-*- coding:utf-8 -*-
import  numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x,a,b):
    return a * np.exp(-x * b)

x = np.array([0,1,2,3,4,5,6,7,8,9,10])
y = np.array([10023,8174,6693,5500,4489,3683,3061,2479,2045,1645,1326])

plt.scatter(x,y)

ppot,pcov = curve_fit(func,x,y)

x1 = np.arange(0,15,0.01)
y1 = func(x1,ppot[0],ppot[1])
y2 = 10037 * np.exp(-0.2005*x1)
plt.plot(x1,y1,c='r')
plt.plot(x1,y2,c='b')
print "ppot = ",ppot

plt.show()