import numpy as np
import matplotlib.pyplot as plt

def func(x):
    if np.all(x) != -1:
        return (x ** 3 - x ** 2 - 5 * x - 3) / ((x + 1) ** 2)

x = np.arange(-2,1,0.001)
y = func(x)

plt.plot(x,y)
plt.show()