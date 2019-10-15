import math

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

Widerstand = (1000, 800, 600, 400, 300, 250, 200, 150, 120, 100, 80, 60)
Spannung = (92.1, 85.7, 80.5, 71.4, 64.1, 59.6, 52.8, 45.1, 41.4, 34.2, 31, 25)
plt.xlim(0, 1100)
plt.ylim(0, 100)
plt.title('Quellenwiderstand')
plt.ylabel('Spannung in mV')
plt.xlabel('Widerstand in Ω')
plt.grid(1)
plt.plot(Widerstand, Spannung, 'o',markersize = 5,  color = 'blue', linestyle = 'dashed', linewidth = 1 ) 
plt.savefig('Quellenwiderstand.jpg')
plt. show()