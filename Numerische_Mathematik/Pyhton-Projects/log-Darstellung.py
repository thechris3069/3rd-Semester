import math

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

x = np.arange(0.001, 100, 0.01)
y = 100-x
plt.xlim(0, 100)
plt.ylim(0, 100)
plt.plot(x,y)
plt.show()