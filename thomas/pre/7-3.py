#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

x = np.array([20,25,30,35,40,45,50,55,60,65,70,75])
y = np.array([32,47,65,87,112,140,171,204,241,282,325,376])

plt.scatter(x,y)
z = np.polyfit(x,y,2)
x1 = np.arange(10,120)
y1 = z[0] * x1 * x1 + z[1] * x1 + z[2]
plt.plot(x1,y1)
print "z = ",z
plt.show()