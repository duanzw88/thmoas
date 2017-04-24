
import numpy as np
import matplotlib.pyplot as plt
x = np.arange(0,1,0.001)
y1 = np.sqrt(x)
y2 = np.sqrt(1-x)
y3 = y1 + y2

plt.plot(x,y1)
plt.plot(x,y2)
plt.plot(x,y3)
plt.show()