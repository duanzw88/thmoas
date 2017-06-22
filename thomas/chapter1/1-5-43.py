
import base

import  numpy as np
import matplotlib.pyplot as plt

def fun5_43(x):
    ret = np.where(x <= 0,-np.sqrt(np.fabs(x)),np.sqrt(x));
    return ret;


x1 = np.linspace(-5.0,5.0,100)
y1 = fun5_43(x1)

plt.plot(x1,y1,'r')
plt.xlim(-5,5)
plt.ylim(-10,10)
plt.show()