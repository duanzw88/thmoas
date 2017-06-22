#-*- coding:utf-8 -*-
# 把f1和f2的图形画在一起，然后说明在作用f1之前取绝对值会怎样影响图形
#       f1(x)       f2(x)=f1(|x|)
# 47:   x               |x|
# 48:   x ** 3          |x| ** 3
# 49:   x ** 2          |x| ** 2
# 50:   1 / x           1 / |x|
# 51:   sqrt(x)         sqrt(|x|)
# 52:   sin(x)          sin(|x|)
#
import numpy as np
import matplotlib.pyplot as plt

plt.figure(figsize=(16,8))
#分割
ax1 = plt.subplot2grid((2,3),(0,0),rowspan=1,colspan=1)
x47 = np.arange(-5,5,0.1)
f1_47 = x47
f2_47 = np.abs(x47)
ax1.set_title("47");
ax1.spines['top'].set_color('none')
ax1.spines['right'].set_color('none')
ax1.xaxis.set_ticks_position('bottom')
ax1.spines['bottom'].set_position(('data',0))
ax1.yaxis.set_ticks_position('left')
ax1.spines['left'].set_position(('data',0))
ax1.plot(x47,f1_47,c='r',label="f1(x) = x")
ax1.plot(x47,f2_47,c='b',label="f2(x) = |x|")
ax1.legend(loc='best')

ax2 = plt.subplot2grid((2,3),(0,1),rowspan=1,colspan=1)
x48 = np.arange(-3,3,0.1)
f1_48 = x48 ** 3
f2_48 = np.abs(x48) ** 3
ax2.set_title("48")
ax2.spines['top'].set_color('none')
ax2.spines['right'].set_color('none')
ax2.xaxis.set_ticks_position('bottom')
ax2.spines['bottom'].set_position(('data',0))
ax2.yaxis.set_ticks_position('left')
ax2.spines['left'].set_position(('data',0))
ax2.plot(x48,f1_48,c='r',label="f1(x) = x ** 3")
ax2.plot(x48,f2_48,c='b',label="f2(x) = |x| ** 3")
ax2.legend(loc='best')

ax3 = plt.subplot2grid((2,3),(0,2),rowspan=1,colspan=1)
x49 = np.arange(-3,3,0.1)
f1_49 = x49 ** 2
f2_49 = np.abs(x49) ** 2
ax3.set_title("49")
ax3.spines['top'].set_color('none')
ax3.spines['right'].set_color('none')
ax3.xaxis.set_ticks_position('bottom')
ax3.spines['bottom'].set_position(('data',0))
ax3.yaxis.set_ticks_position('left')
ax3.spines['left'].set_position(('data',0))
ax3.plot(x49,f1_49,c='r',label="f1(x) = x ** 2")
ax3.plot(x49,f2_49,c='b',label="f2(x) = |x| ** 2")
ax3.legend(loc='best')

ax4 = plt.subplot2grid((2,3),(1,0),rowspan=1,colspan=1)
x50 = np.arange(-3,3,0.1)
f1_50 = 1 / x50
f2_50 = 1 / np.abs(x50)
ax4.set_title("50")
ax4.set_ylim(-5,5)
ax4.spines['top'].set_color('none')
ax4.spines['right'].set_color('none')
ax4.xaxis.set_ticks_position('bottom')
ax4.spines['bottom'].set_position(('data',0))
ax4.yaxis.set_ticks_position('left')
ax4.spines['left'].set_position(('data',0))
ax4.plot(x50,f1_50,c='r',label="f1(x) = 1 / x")
ax4.plot(x50,f2_50,c='b',label="f2(x) = 1 / |x|")
ax4.legend(loc='best')

ax5 = plt.subplot2grid((2,3),(1,1),rowspan=1,colspan=1)
x51 = np.arange(-3,3,0.1)
f1_51 = np.sqrt(x51)
f2_51 = np.sqrt(np.abs(x51))
ax5.set_title("51")
ax5.spines['top'].set_color('none')
ax5.spines['right'].set_color('none')
ax5.xaxis.set_ticks_position('bottom')
ax5.spines['bottom'].set_position(('data',0))
ax5.yaxis.set_ticks_position('left')
ax5.spines['left'].set_position(('data',0))
ax5.plot(x51,f1_51,c='r',label="f1(x) = sqrt(x)")
ax5.plot(x51,f2_51,c='b',label="f2(x) = sqrt(|x|)")
ax5.legend(loc='best')

ax6 = plt.subplot2grid((2,3),(1,2),rowspan=1,colspan=1)
x52 = np.arange(-10,10,0.1)
f1_52 = np.sin(x52)
f2_52 = np.sin(np.abs(x52))
ax6.set_title("52")
ax6.spines['top'].set_color('none')
ax6.spines['right'].set_color('none')
ax6.xaxis.set_ticks_position('bottom')
ax6.spines['bottom'].set_position(('data',0))
ax6.yaxis.set_ticks_position('left')
ax6.spines['left'].set_position(('data',0))
ax6.plot(x52,f1_52,c='r',label="f1(x) = sin(x)")
ax6.plot(x52,f2_52,c='b',label="f2(x) = sin(|x|)")
ax6.legend(loc='best')

# plt.legend(loc='bottom right')
plt.show()