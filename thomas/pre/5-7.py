#-*- coding:utf-8 -*-

#7
# (a):sin(2x)
#sinx周期为2pi,所以sin2x周期为2pi/2=pi
# (b):cos(pi*x)
#cosx周期为2pi，所以cos(pi*x)周期为2pi/pi = 2
#
#
from numpy import *
import matplotlib.pyplot as plt

x = arange(-5,5,0.1)
# x = array([-3*pi,-5*pi/2,-2*pi,-3*pi/2,-1*pi,-1*pi/2,0,pi/2,pi,3*pi/2,2*pi,5*pi/2,3*pi])
y = sin(2*x)
plt.plot(x,y)
plt.show()