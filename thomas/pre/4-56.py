#-*- coding:utf-8 -*-
#证实商法则
# 设y1=ln(x/a) y2=ln(x) y3-y2-y1以及y4=e(y3)
# (a):对a=2,3,4,5画y1和y2的图形，y1和y2有怎么样的关系
# (b):对a=2,3,4,5画y3的图形，描述这些图形
# (c):对a=2,3,4,5画y4的图形
# (d):用e(y3)=e(y2-y1)解y1

import numpy as np
import matplotlib.pyplot as plt

x = np.arange(1,10,0.1)
a = 2
y1 = np.log(x / a)
y2 = np.log(x)
y3=y2-y1
y4=np.exp(y3)
plt.plot(x,y1,c='r',label="y1=log(x/a)")
plt.plot(x,y2,c='g',label="y2=log(x)")
plt.plot(x,y3,c='c',label="y3=y2-y1")
plt.plot(x,y4,c='m',label="y4=e(y3)")
plt.legend(loc='bottom left')
plt.show()