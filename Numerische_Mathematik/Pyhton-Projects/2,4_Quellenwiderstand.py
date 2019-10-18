import math

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

Widerstand = (1000, 800, 600, 400, 300, 250, 200, 150, 120, 100, 80, 60)
Spannung = (92.1, 85.7, 80.5, 71.4, 64.1, 59.6, 52.8, 45.1, 41.4, 34.2, 31, 25)
Strom = tuple(np.divide( Spannung, Widerstand))
Leistung = tuple(np.multiply( Spannung, Spannung))
Leistung = tuple(np.divide( Leistung, Widerstand))
print(Strom)
print(Leistung)

plt.grid(1)

# Darstellung vom Strom 

# plt.title('Quellenwiderstand')
# plt.ylabel('Spannung in mV')
# plt.xlabel('Widerstand in Ω')
# plt.xlim(0, 1100)
# plt.ylim(0, 100
# plt.plot(Widerstand, Spannung, 'o',markersize = 5,  color = 'blue', linestyle = 'dashed', linewidth = 0 ) 
# plt.savefig('Quellenwiderstand.jpg')
# plt. show()





# Linearisierung

element = 0
matrix = [[0,0],[0,len(Spannung)]]
result = [0,0]
while element  < len(Spannung):
    matirxtmp = [[Spannung[element]**2, Spannung[element]], [Spannung[element], 0]]
    matrix = np.add(matrix, matirxtmp)
    tmp_result = [Spannung[element]*Strom[element], Strom[element]]
    result = np.add(result, tmp_result)
    element = element+1
det = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]
det_a = result[0]*matrix[1][1]-result[1]*matrix[0][1]
det_b = result[1]*matrix[0][0] - matrix[1][0]*result[0]
a = det_a/det
b = det_b/det
x = np.arange(24, 93, 1)
print("Median ascent:{:0.2f} + {:0.2f} x ".format(a,b))
print("Median ascent: y = ",a, "*x+",b )
plt.title("Median ascent:{:0.2f} + {:0.2f} x ".format(a,b))

y_gerade = a*x+b
# plt.plot(x,y_gerade)
# plt.ylabel("Strom")
# plt.xlabel('Spannung')
plt.grid(1)
plt.axes = True
# plt.show()


# plt.title('I/U - Diagramm')
# plt.xlim(0, 100)
# plt.ylim(0, 0.5)
# plt.xlabel('Spannung in mV')
# plt.ylabel('Stromstärke in mA')

# plt.plot(x, y_gerade, markersize = 3, color = 'red', linestyle = 'dashed', linewidth = 1 ) 

# plt.plot(Spannung, Strom, 'o',markersize = 6,  color = 'black', linestyle = 'dashed', linewidth = 0 ) 
# plt.savefig('U-I-Diagramm.jpg')
# plt.show()


plt.xlim(0, 1100)
plt.ylim(0, 15)
plt.title('P/R - Kennlinie')
plt.xlabel('Widerstand in Ω')
plt.ylabel('Leistung in μW')
plt.plot(Widerstand, Leistung, 'o',markersize = 5,  color = 'blue', linestyle = 'dashed', linewidth = 0 ) 
plt.savefig('Leistung.jpg')
plt.show()

