
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-2,2,0.001)
y1 = 4 - x ** 2
y2 = np.sqrt(x)
y3 = np.sqrt(4 - x ** 2)
y4 = 4 - np.sqrt(x) ** 2

plt.plot(x,y1)
plt.plot(x,y2)
# plt.plot(x,y3)
plt.plot(x,y4)
plt.show()