#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
#40
#函数及其倒数
# (a) 对-3pi/2 <= x <= 3pi/2 把y=cos(x)和y=sec(x)画在一起，说明secx和cosx的正负号和值的关系
# (b) 对-pi <= x <= 2pi 把y=sin(x)和y=csc(x)画在一起，说明sinx和cscx的正负号和值的关系
# #

#(a):
fig1 = plt.figure("fig1")
x = np.arange(-3 * np.pi / 2,3 * np.pi / 2,0.05*np.pi)
# x = np.arange(-3,3,0.01)
y_cos = np.cos(x)
y_sec = 1 / y_cos

plt.ylim(-5,5)
plt.plot(x,y_cos,c='r',label="cos(x)")
plt.plot(x,y_sec,c='b',label="sec(x)")
plt.legend()
plt.show()


#(b)
fig2 = plt.figure("fig2")
x1 = np.arange(-2 * np.pi,2 * np.pi,0.05*np.pi)
y1_sin = np.sin(x1)
y1_csc = 1 / y1_sin
plt.ylim(-5,5)
plt.plot(x1,y1_sin,c='r',label="sin(x)")
plt.plot(x1,y1_csc,c='b',label="csc(x)")
plt.legend()
plt.show()