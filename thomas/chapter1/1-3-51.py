import numpy as np
import matplotlib.pyplot as plt

def fun51(x):
    return (1 / x)  * np.exp(1 / x)

x1 = np.linspace(-4,-0.01,100)
y1 = fun51(x1)

x2 = np.linspace(0.01,4,100)
y2 = fun51(x2)

plt.plot(x1,y1,x2,y2)
plt.xlim(-1,4)
plt.ylim(-1,3)
plt.show()