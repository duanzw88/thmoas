#-*- coding:utf-8 -*-

import numpy
import matplotlib.pyplot as plt

x = numpy.array([20,25,30,35,40,45,50,55,60,65,70,75,80])
y = numpy.array([42,56,73.5,91.5,116,142.5,173,209.5,248,292.5,343,401,464])

plt.scatter(x,y)
z = numpy.polyfit(x,y,2)
print "z = ",z

y1 = z[0] * (x ** 2) + z[1] * x + z[2]
plt.plot(x,y,'r-')

result_72 = z[0] * (72 ** 2) + z[1] * 72 + z[2]
result_85 = z[0] * (85 ** 2) + z[1] * 85 + z[2]
print "72 = %.2f 85 = %.2f" %(result_72,result_85)

z2 = numpy.polyfit(x,y,1)
print "z2 = ",z2
y2 = z2[0] * x + z2[1]
plt.plot(x,y,'b-')
result2_72 = z2[0] * 72 + z2[1]
result2_85 = z2[0] * 85 + z2[1]
print "72 = %.2f 85 = %.2f" %(result2_72,result2_85)
plt.show()