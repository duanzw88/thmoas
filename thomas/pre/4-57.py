#-*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator,FormatStrFormatter

xmajorLocator = MultipleLocator(1)
xmajorFormatter = FormatStrFormatter('%1.1f')
xminorLocator = MultipleLocator(0.5)


x = np.arange(-5,5,0.1)
y = x ** 2 - np.power(2,x)
y2= x * 0

#获取figure和axis
fig = plt.figure(figsize=(4,4))
ax = fig.add_subplot(111)
ax.spines['top'].set_color('none')
ax.spines['right'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))

#设置主刻度标签的位置，标签的文本格式
ax.xaxis.set_major_locator(xmajorLocator)
ax.xaxis.set_major_formatter(xmajorFormatter)
ax.xaxis.set_minor_locator(xminorLocator)
plt.plot(x,y)
plt.plot(x,y2,c='r')
plt.show()