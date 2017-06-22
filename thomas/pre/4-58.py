#-*- coding:utf-8 -*-
#4.58:对x>0 x(ln2)和2(lnx)一样吗？画出这两个函数的图形，说明你看到了什么
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0.1,8,0.1)
y1 = np.power(x,np.log(2))
y2 = np.power(2,np.log(x))



plt.plot(x,y1,c='r',label="x(ln2)")
plt.plot(x,y2,c='b',label="2(lnx)")
plt.legend('bottom')
plt.show()