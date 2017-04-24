#-*- coding:utf-8 -*-
import numpy
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x,a,b):
    return a * (b ** x)

x = numpy.array([50,60,70,80,90])
y = numpy.array([25.8,34.9,48.2,66.8,81.1])
plt.scatter(x,y)
ppot,pcov = curve_fit(func,x,y)
print "ppot = ",ppot
x1 = numpy.linspace(0,100,100)
y2 = [func(i,ppot[0],ppot[1]) for i in x1]
y3 = [func(i,6.033,1.030) for i in x1]
plt.xlim(0)
plt.ylim(0)
plt.plot(x1,y2,'r-')
plt.plot(x1,y3,'b-')

plt.show()

result_1900 = func(0,ppot[0],ppot[1])