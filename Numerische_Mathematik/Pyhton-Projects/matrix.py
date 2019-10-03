import math

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

x = 1
i = range(1,20)
j = 0
delta = []
while(j <19):
    h = 10**-i[j]
    fx = math.sin(x)
    fxtilde = math.sin(x+h)
    delta.append(fxtilde -fx)
    print('delta = ',delta[j], 'for i = ', i[j])

    j = j+1
plt.plot(i, delta, markersize = 2)



# plt.xlim(0,9)
plt.ylim(0,0.01)

plt.show()
print('Hello World')