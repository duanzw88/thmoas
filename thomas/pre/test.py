#-*- coding:utf-8 -*-

import  numpy as np
import  matplotlib.pyplot as plt

# x = np.arange(-2,2,0.1)
# y = 1 / ((4 - x * x) ** 0.5)
# plt.plot(x,y)
# plt.show()
#参数化反函数(p-6)

# t = np.arange(0,3,0.01)
# x1 = t
# y1 = t ** 2
#
# x2 = t ** 2
# y2 = t
#
# x3 = t
# y3 = t
#
# plt.plot(x1,y1,c='r')
# plt.plot(x2,y2,c='g')
# plt.plot(x3,y3,c='b')
# plt.show()


#预测司机反应距离
x = np.array([20,25,30,35,40,45,50,55,60,65,70,75,80])
y = np.array([22,28,33,39,44,50,55,61,66,72,77,83,88])

y_result = 1.1 * x
plt.scatter(x,y)
plt.plot(x,y_result)
plt.show()