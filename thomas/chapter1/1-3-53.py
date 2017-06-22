import numpy as np
import matplotlib.pyplot as plt

def fun53(x):
    return x * np.log(np.abs(1 / x))

x1 = np.linspace(-4,-0.01,100)
y1 = fun53(x1)

x2 = np.linspace(0.01,4,100)
y2 = fun53(x2)

plt.plot(x1,y1,x2,y2)
plt.xlim(-3,3)
plt.ylim(-2,2)
plt.show()