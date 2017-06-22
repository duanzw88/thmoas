#-*- coding:utf-8 -*-
# 把g1和g2的图形画在一起，然后说明在作用g1之前取绝对值会怎样影响图形
#       f1(x)       f2(x)=f1(|x|)
# 53:   x ** 3          |x ** 3|
# 54:   sqrt(x)         |sqrt(x)|
# 55:   4 - x ** 2      |4 - x ** 2|
# 56:   x ** 2 + x      |x ** 2 + x|
#
import numpy as np
import matplotlib.pyplot as plt

plt.figure(figsize=(16,8))
#分割
ax1 = plt.subplot2grid((2,2),(0,0),rowspan=1,colspan=1)
x53 = np.arange(-5, 5, 0.1)
f1_53 = x53 ** 3
f2_53 = np.abs(f1_53)
ax1.set_title("53");
ax1.spines['top'].set_color('none')
ax1.spines['right'].set_color('none')
ax1.xaxis.set_ticks_position('bottom')
ax1.spines['bottom'].set_position(('data',0))
ax1.yaxis.set_ticks_position('left')
ax1.spines['left'].set_position(('data',0))
ax1.plot(x53, f1_53, c='r', label="f1(x) = x")
ax1.plot(x53, f2_53, c='b', label="f2(x) = |x|")
ax1.legend(loc='best')

ax2 = plt.subplot2grid((2,2),(0,1),rowspan=1,colspan=1)
x54 = np.arange(-3, 3, 0.01)
f1_54 = np.sqrt(x54)
f2_54 = np.abs(f1_54)
ax2.set_title("54")
ax2.spines['top'].set_color('none')
ax2.spines['right'].set_color('none')
ax2.xaxis.set_ticks_position('bottom')
ax2.spines['bottom'].set_position(('data',0))
ax2.yaxis.set_ticks_position('left')
ax2.spines['left'].set_position(('data',0))
ax2.plot(x54, f1_54, c='r', label="f1(x) = np.sqrt(x)")
ax2.plot(x54, f2_54, c='b', label="f2(x) = |f1(x)|")
ax2.legend(loc='best')

ax3 = plt.subplot2grid((2,2),(1,0),rowspan=1,colspan=1)
x55 = np.arange(-3,3,0.1)
f1_55 = 4 - x55 ** 2
f2_55 = np.abs(f1_55)
ax3.set_title("55")
ax3.spines['top'].set_color('none')
ax3.spines['right'].set_color('none')
ax3.xaxis.set_ticks_position('bottom')
ax3.spines['bottom'].set_position(('data',0))
ax3.yaxis.set_ticks_position('left')
ax3.spines['left'].set_position(('data',0))
ax3.plot(x55,f1_55,c='r',label="f1(x) = 4 - x ** 2")
ax3.plot(x55,f2_55,c='b',label="f2(x) = |f1(x)|")
ax3.legend(loc='best')

ax4 = plt.subplot2grid((2,2),(1,1),rowspan=1,colspan=1)
x56 = np.arange(-3,3,0.1)
f1_56 = x56 ** 2 + x56
f2_56 = np.abs(f1_56)
ax4.set_title("56")
ax4.set_ylim(-5,5)
ax4.spines['top'].set_color('none')
ax4.spines['right'].set_color('none')
ax4.xaxis.set_ticks_position('bottom')
ax4.spines['bottom'].set_position(('data',0))
ax4.yaxis.set_ticks_position('left')
ax4.spines['left'].set_position(('data',0))
ax4.plot(x56,f1_56,c='r',label="f1(x) = x**2 + x")
ax4.plot(x56,f2_56,c='b',label="f2(x) = |f1(x)|")
ax4.legend(loc='best')


plt.show()