#-*- coding:utf-8 -*-
import  numpy as np
import matplotlib.pyplot as plt

# x = np.arange(0,10000,1)
# y = (1 + 1 / x) ** x
# plt.plot(x,y)
# plt.show()

# def sigmoid(inX):
#     return 1.0 / (1 + np.exp(-inX))
#
# x = np.arange(-10,10,0.001)
# # print "x = ",x
# y = sigmoid(x)
#
# plt.xlim((-10,10))
# plt.ylim((-0.5,1.5))
# plt.plot(x,y)
# plt.show()


x = np.arange(0,10,0.001)
y = np.sin(1/x)
plt.ylim(-2,2)
plt.plot(x,y)
plt.show()