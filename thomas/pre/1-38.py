import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

x = [[1980],[1985],[1988],[1989],[1990]]
y = [[22033],[27581],[30466],[31465],[32836]]
plt.scatter(x,y)

clf = linear_model.LinearRegression()
clf.fit(x,y)
a = clf.coef_
b = clf.intercept_
print "a = ",a
print "b = ",b
x1 = np.arange(1975,2000,5)
y1 = a[0] * x1 + b[0]
plt.plot(x1,y1)
plt.show()