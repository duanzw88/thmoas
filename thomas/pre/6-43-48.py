#-*- coding:utf-8 -*-
#43:椭圆：x = 4cos(t) y = 2sin(t)在
#(a):0 <= t <=2pi (b):0 <= t <= pi (c):-pi/2 <= t <= pi/2
#
#44 双曲线分支x = sec(t) y = tan(t)
#(a) -1.5 <= t <= 1.5 (b) -0.5 <= t <= 0.5 (c) -0.1 <= t <= t
#
#45:抛物线：x = 2t + 3 y = t**2 - 1, -2 <= t <= 2
#
#46:一条优美的曲线
# x = 2cos(t) + cos(2t)  y = 2sin(t) - sin(2t)    0 <= t <= 2pi
#如果在x和y中用-2代替2 结果将会怎么样，画出新的方案图
#
#47：一条更优美的曲线
#x = 3cos(t) + cos(3t) y = 3sin(t) - sin3t   0 <= t <= 2pi
#
# 48:选轮线，x = t - sin(t) y = 1 - cos(t)
# (a) 0 <= t <= 2pi (b) 0 <= t <= 4pi （c) pi <= t <= 3pi
# #
import numpy as np
import matplotlib.pyplot as plt

ax43 = plt.subplot2grid((3,2),(0,0),rowspan=1,colspan=1)
#调整坐标轴
ax43.spines['top'].set_color('none')
ax43.spines['right'].set_color('none')
ax43.xaxis.set_ticks_position('bottom')
ax43.spines['bottom'].set_position(('data',0))
ax43.yaxis.set_ticks_position('left')
ax43.spines['left'].set_position(('data',0))
t = np.arange(0,2 * np.pi,0.01 * np.pi)
x = 4 * np.cos(t)
y = 2 * np.sin(t)
ax43.plot(x,y,c='r',label="a")
ax43.legend(loc='best')

ax44 = plt.subplot2grid((3,2),(0,1),rowspan=1,colspan=1)
#调整坐标轴
ax44.spines['top'].set_color('none')
ax44.spines['right'].set_color('none')
ax44.xaxis.set_ticks_position('bottom')
ax44.spines['bottom'].set_position(('data',0))
ax44.yaxis.set_ticks_position('left')
ax44.spines['left'].set_position(('data',0))
t44 = np.arange(-1.5,1.5,0.01)
x44 = 1 / np.cos(t44)
y44 = np.tan(t44)
ax44.plot(x44,y44,c='r',label="44(a)")

ax45 = plt.subplot2grid((3,2),(1,0),rowspan=1,colspan=1)
ax45.spines['top'].set_color('none')
ax45.spines['right'].set_color('none')
ax45.xaxis.set_ticks_position('bottom')
ax45.spines['bottom'].set_position(('data',0))
ax45.yaxis.set_ticks_position('left')
ax45.spines['left'].set_position(('data',0))
t45 = np.arange(-2,2,0.01)
x45 = 2 * t45 + 3
y45 = t45 ** 2 - 1
ax45.set_xlim(-2,8)
ax45.plot(x45,y45,c='b',label="45")

ax46 = plt.subplot2grid((3,2),(1,1),rowspan=1,colspan=1)
ax46.spines['top'].set_color('none')
ax46.spines['right'].set_color('none')
ax46.xaxis.set_ticks_position('bottom')
ax46.spines['bottom'].set_position(('data',0))
ax46.yaxis.set_ticks_position('left')
ax46.spines['left'].set_position(('data',0))
t46 = np.arange(0,2*np.pi,0.01*np.pi)
x46 = 2 * np.cos(t46) + np.cos(2*t46)
y46 = 2 * np.sin(t46) - np.sin(2 * t46)
x46_2 = -2 * np.cos(t46) + np.cos(-2*t46)
y46_2 = -2 * np.sin(t46) - np.sin(-2 * t46)
ax46.plot(x46,y46,c='r',label="46_1")
ax46.plot(x46_2,y46_2,c='g',label="46_2")
ax46.legend(loc='best')


ax47 = plt.subplot2grid((3,2),(2,0),rowspan=1,colspan=1)
ax47.spines['top'].set_color('none')
ax47.spines['right'].set_color('none')
ax47.xaxis.set_ticks_position('bottom')
ax47.spines['bottom'].set_position(('data',0))
ax47.yaxis.set_ticks_position('left')
ax47.spines['left'].set_position(('data',0))
t47 = np.arange(0,2*np.pi,0.01*np.pi)
x47 = 3*np.cos(t47) + np.cos(3*t47)
y47 = 3*np.sin(t47) - np.sin(3*t47)
x47_b = -3*np.cos(t47) + np.cos(-3*t47)
y47_b = -3*np.sin(t47) - np.sin(-3*t47)
ax47.plot(x47,y47,c='r',label="47(a)")
ax47.plot(x47_b,y47_b,c='b',label="47(b)")
ax47.legend(loc='best')

ax48 = plt.subplot2grid((3,2),(2,1),rowspan=1,colspan=1)
ax48.spines['top'].set_color('none')
ax48.spines['right'].set_color('none')
ax48.xaxis.set_ticks_position('bottom')
ax48.spines['bottom'].set_position(('data',0))
ax48.yaxis.set_ticks_position('left')
ax48.spines['left'].set_position(('data',0))
t48 = np.arange(0,4*np.pi,0.01*np.pi)
x48 = t48 - np.sin(t48)
y48 = 1 - np.cos(t48)
ax48.plot(x48,y48)
plt.show()