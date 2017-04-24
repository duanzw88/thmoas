#-*- coding:utf-8 -*-
import numpy
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x,a,b):
    return a * (b ** x)

x = numpy.array([4,11,36,46,51,60,70,80])
y = numpy.array([5.2,6.0,9.6,11.4,12.7,16.0,18.3,20.6])

plt.scatter(x,y)
ppot,pcov = curve_fit(func,x,y)
print "ppot = ",ppot
print "pcov = ",pcov

plt.xlim(0)
plt.ylim(0)
y2 = [func(i,ppot[0],ppot[1]) for i in x]
plt.plot(x,y2,'r-')
plt.show()