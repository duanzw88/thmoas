
import numpy as np
import matplotlib.pyplot as plt
import math

# x = np.linspace(0,1,1000)
x = np.arange(0,1,0.0001)
f = np.sqrt(x)
g = np.sqrt(1 - x)

a = f + g
a1 = np.sqrt(x) + np.sqrt(1-x)
b = f * g
c1 = f - g
c2 = g - f
d1 = f / g
d2 = g / f
plt.plot(x,f);
plt.plot(x,g);
plt.plot(x,a)
plt.plot(x,a1)
# plt.plot(x,b)
plt.plot(x,c1)
# plt.plot(x,c2)
# plt.plot(x,d1)
# plt.plot(x,d2)

plt.show()