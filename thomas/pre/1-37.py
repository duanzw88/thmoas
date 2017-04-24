import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model
x = [[19],[21],[24],[27],[29],[31],[34],[38],[43]]
y = [[22],[23],[25],[28],[31],[28],[32],[34],[39]]

plt.xlim(0,50)
plt.ylim(0,50)
plt.scatter(x,y)
# plt.show()

clf = linear_model.LinearRegression()
clf.fit(x,y)
b = clf.intercept_
a = clf.coef_
print "a = ",a
print "b = ",b
x1 = np.arange(1,50)
y1 = a[0] * x1 + b[0]
plt.plot(x1,y1)
plt.show()