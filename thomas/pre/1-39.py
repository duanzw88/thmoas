#-*- coding:utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

x = [[1970],[1975],[1980],[1985],[1990]]
y1 = [[25200],[39300],[60800],[88900],[141200]]
y2 = [[20100],[30100],[51900],[58900],[74000]]

clf = linear_model.LinearRegression()
clf.fit(x,y1)
a1 = clf.coef_
b1 = clf.intercept_
print "a1 = ",a1
print "b1 = ",b1
x11 = np.arange(1960,2000,5)
y11 = a1[0] * x11 + b1[0]
plt.scatter(x,y1,color='m',label='E')
plt.plot(x11,y11,color='m')

clf.fit(x,y2)
a2 = clf.coef_
b2 = clf.intercept_
print "a2 = ",a2
print "b2 = ",b2
y22 = a2[0] * x11 + b2[0]
plt.scatter(x,y2,color='r',label='W')
plt.plot(x11,y22,color='r')
plt.show()

