#-*- coding:utf-8 -*-

import numpy
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def func(x,a,b):
    return a * (x ** b)
def polyfit(x,y,degree):
    results = {}

    results['polynomial'] = popt

x = numpy.array([0.20,0.65,1.13,2.55,4.00,5.75,7.80,10.20,12.90,16.00,18.40])
y = numpy.array([1.8,3.6,5.4,7.2,9.0,10.8,12.6,14.4,16.2,18.0,19.8])

plt.scatter(x,y)

#幂函数预测
popt, pcov = curve_fit(func, x, y)
print "popt = ",popt
y2 = [func(i,popt[0],popt[1]) for i  in x]
plt.plot(x,y2,'r----')

result = func(11,popt[0],popt[1])
print "result = ",result

#线性拟合
z1 = numpy.polyfit(x,y,1)
print "z1 = ",z1

y3 = z1[0] * x + z1[1]
plt.plot(x,y3,'b-')
result3 = z1[0] * 11 + z1[1]
print "result3 = ",result3
plt.show()