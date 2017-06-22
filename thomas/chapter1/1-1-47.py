import numpy as np
import matplotlib.pyplot as plt

def func(x):
    if np.all(x) == 2:
        return  (np.power(x,2) + 4) * (x + 2)
    else:
        return (np.power(x,4) - 16) / (x - 2)

x = np.arange(-5,5,0.01)
y = func(x)

plt.plot(x,y)
plt.show()