
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-100,100,1)
f = x - 7
g = x ** 2

fg = f * g
gf = g * f
plt.plot(x,fg)
plt.plot(x,gf)
plt.show()