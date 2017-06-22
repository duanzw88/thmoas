import numpy as np
import matplotlib.pyplot as plt

def func(x):
    return x * np.sin(1/x)

x_left1 = -0.1
x_left2 = -0.01
x_left3 = -0.001
x_left4 = -0.0001

x_right2 = 0.0001
x_right3 = 0.001
x_right4 = 0.01
x_right5 = 0.1

y_left1 = func(x_left1)
y_left2 = func(x_left2)
y_left3 = func(x_left3)
y_left4 = func(x_left4)

y_right2 = func(x_right2)
y_right3 = func(x_right3)
y_right4 = func(x_right4)
y_right5 = func(x_right5)

print "%.1f,%f" %(x_left1,y_left1)
print "%.2f,%f" %(x_left2,y_left2)
print "%.3f,%f" %(x_left3,y_left3)
print "%.4f,%f" %(x_left4,y_left4)

print "%.2f,%f" %(x_right2,y_right2)
print "%.3f,%f" %(x_right3,y_right3)
print "%.4f,%f" %(x_right4,y_right4)
print "%.5f,%f" %(x_right5,y_right5)



