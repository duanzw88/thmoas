#-*- coding:utf-8 -*-
import  numpy as np
import matplotlib.pyplot as plt

#获取figure和axis
fig = plt.figure(figsize=(4,4))
ax = fig.add_subplot(111)
ax.spines['top'].set_color('none')
ax.spines['right'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))