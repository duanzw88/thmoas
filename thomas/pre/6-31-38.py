#-*- coding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

ax1 = plt.subplot2grid((2,4),(0,0),rowspan=1,colspan=1)
x1 = np.arange(0.1,3,0.1)
y1 = np.exp(x1)
yx1 = x1
y11 = np.log(x1)

ax1.plot(x1,y1,'r',x1,yx1,'g',x1,y11,'b');

ax2 = plt.subplot2grid((2,4),(0,1),rowspan=1,colspan=1)
x2 = np.arange(0.1,3,0.1)
y2 = np.power(3,x2)
yx2 = x2
y12 = np.log(x2) / np.log(3)
ax2.plot(x2,y2,'r',x2,yx2,'g',x2,y12,'b');

ax3 = plt.subplot2grid((2,4),(0,2),rowspan=1,colspan=1)
x3 = np.arange(0.1,3,0.1)
y3 = np.power(2,1/x3)
yx3 = x3
y13 = np.log(1/x3) / np.log(2)
ax3.plot(x3,y3,'r',x3,yx3,'g',x3,y13,'b');

ax4 = plt.subplot2grid((2,4),(0,3),rowspan=1,colspan=1)
x4 = np.arange(0.1,3,0.1)
y4 = np.power(3,1/x4)
yx4 = x4
y14 = np.log(1/x4) / np.log(3)
ax4.plot(x4,y4,'r',x4,yx4,'g',x4,y14,'b');

ax5 = plt.subplot2grid((2,4),(1,0),rowspan=1,colspan=1)
x5 = np.arange(0.1,3,0.1)
y5 = np.log(x5)
yx5 = x5
y15 = np.exp(x5)
ax5.plot(x5,y5,'r',x5,yx5,'g',x5,y15,'b');

ax6 = plt.subplot2grid((2,4),(1,1),rowspan=1,colspan=1)
x6 = np.arange(0.1,3,0.1)
y6 = np.log10(x5)
yx6 = x6
y16 = np.power(10,x6)
ax6.plot(x6,y6,'r',x6,yx6,'g',x6,y16,'b');

ax7 = plt.subplot2grid((2,4),(1,2),rowspan=1,colspan=1)
x7 = np.arange(-1,1,0.1)
y7 = np.arcsin(x7)
yx7 = x7
y17 = np.sin(x7)
ax7.plot(x7,y7,'r',x7,yx7,'g',x7,y17,'b');

ax8 = plt.subplot2grid((2,4),(1,3),rowspan=1,colspan=1)
x8 = np.arange(-np.pi/2,np.pi/2,0.1*np.pi)
y8 = np.arctan(x8)
yx8 = x8
y18 = np.tan(x8)
ax8.plot(x8,y8,'r',x8,yx8,'g',x8,y18,'b');


plt.show()




