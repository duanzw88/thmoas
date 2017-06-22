
import base

import  numpy as np
import matplotlib.pyplot as plt


x1 = np.array([3,4,5,6,7])

y1 = np.array([1.5,1.6,2.1,2.6,3.1])

z = np.polyfit(x1,y1,2)
print "z = " ,z

x = np.arange(-1,10,0.01)
y = z[0] * (x ** 2) + z[1] * x + z[2]
plt.scatter(x1,y1)
plt.plot(x,y,'r')

print "y("
plt.xlim(-3,10)
plt.ylim(-1,10)
plt.show()