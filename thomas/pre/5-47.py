#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-3*np.pi,3*np.pi,0.05*np.pi)
y1=np.sin(x)
y2=np.cos(x)
y = np.sin(x) + np.cos(x)
plt.plot(x,y1,c='r',label="sin(x)")
plt.plot(x,y2,c='g',label="cos(x)")
plt.plot(x,y,c='b',label="sin(x)+cox(x)")
plt.legend();
plt.show()