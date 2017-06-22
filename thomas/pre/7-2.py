#-*- coding:utf-8 -*-
import  numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

x = [[0],[1],[2],[3],[4],[5],[6],[7],[8],[9],[10]]
y = [[0],[0.875],[1.721],[2.641],[3.531],[4.391],[5.241],[6.120],[6.992],[7.869],[8.741]]
print "X = ",x
print "y = ",y
plt.scatter(x,y)

clf = linear_model.LinearRegression()
clf.fit(x,y)
a = clf.coef_
b = clf.intercept_
x1 = np.arange(0,11,0.1)
y1 = a[0] * x1 + b[0];
plt.plot(x1,y1,c='r')
print "a = ",a
print "b = ",b
plt.show()