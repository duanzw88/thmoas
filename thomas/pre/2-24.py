#-*- coding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt


x = np.linspace(-5,5,1000)
y = np.where(x < 0,x ** 2,np.where(x>1,2*x-1,x ** 3))
plt.plot(x,y)
plt.show()

