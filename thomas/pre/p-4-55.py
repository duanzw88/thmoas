#-*- coding:utf-8 -*-

#设y1=ln(ax) y2=ln(x) y3=y1-y2
#a:对a=2,3,4,5,画y1 y2的图形
#b:画y3图形
#c:
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(1,10,0.1)
a = 2
y1=np.log(a*x)
y2=np.log(x)
y3=y1-y2
plt.plot(x,y1,c='r')
plt.plot(x,y2,c='g')
plt.plot(x,y3,c='b')
plt.show()
