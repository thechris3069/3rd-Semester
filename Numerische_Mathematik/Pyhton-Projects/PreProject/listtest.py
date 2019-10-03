import csv
import math
from collections import Counter

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

#Fehler bei Berechnung in Falscher Reihenfolge Darstellen
# l = 1.1185557208532343e-05
# print(l)
# i = 1
# k = 0
# while i < 300:
#     k = k + 1/(i*i)
#     i = i+1
# print(k)

# knew = 0
# while i >0:
#     knew = knew +1/(i*i)
#     i = i-1
# print(knew)


xi = [1,2,3,4]
yi = [6,6.8,10,10.5]
plt.plot(xi, yi)
plt.show()

element = 0
matrix = [[0,0],[0,len(xi)]]
result = [0,0]
while element  < len(xi):
    matirxtmp = [[xi[element]**2, xi[element]], [xi[element], 0]]
    matrix = np.add(matrix, matirxtmp)
    tmp_result = [xi[element]*yi[element], yi[element]]
    result = np.add(result, tmp_result)
    element = element+1
det = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]
det_a = result[0]*matrix[1][1]-result[1]*matrix[0][1]
det_b = result[1]*matrix[0][0] - matrix[1][0]*result[0]
a = det_a/det
b = det_b/det
x = np.arange(0.5, 4.5, 0.01)
print("Median ascent:{:0.2f} + {:0.2f} x ".format(a,b))
print("Median ascent: y = ",a, "*x+",b )
plt.title("Median ascent:{:0.2f} + {:0.2f} x ".format(a,b))

y_gerade = a*x+b
plt.plot(x,y_gerade)
plt.ylabel("yi")
plt.xlabel('xi')
plt.grid(1)
plt.axes = True
plt.xlim(0,5)
plt.ylim(0,12)
# plt.plot(xi, y3, color = "red")
# plt.axes.set(xlim=(0, 5), ylim = (0, 12))
plt.plot(xi,yi, color = "black")
plt.show()
# slices = [6, 4,4,3]
# colors = ['blue', 'red', 'green', 'yellow']
# labels = ['Sixty', 'Forty', 'onemore', 'onemor']
# plt.pie(slices, labels = labels, colors = colors, wedgeprops= {'edgecolor': 'black'})
# plt.title('60 - 40 Pie Chart')
# plt.tight_layout()
# plt.legend()

# plt.show()


# plt.style.use("fivethirtyeight")

# ages_x = [25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35]
# x_indexes = np.arange(len(ages_x))
# width = 0.25

# dev_y = [38496, 42000, 46752, 49320, 53200,
#          56000, 62316, 64928, 67317, 68748, 73752]
# plt.bar(x_indexes-width, dev_y, width=width, color="#444444", label="All Devs")

# py_dev_y = [45372, 48876, 53850, 57287, 63016,
#             65998, 70003, 70000, 71496, 75370, 83640]
# plt.bar(x_indexes, py_dev_y, color="#008fd5",width=width, label="Python")

# js_dev_y = [37810, 43515, 46823, 49293, 53437,
#             56373, 62375, 66674, 68745, 68746, 74583]
# plt.bar(x_indexes+width, js_dev_y,width=width, color="#e5ae38", label="JavaScript")

# plt.legend()
# plt.xticks(ticks = x_indexes, labels= ages_x)
# plt.title("Median Salary (USD) by Age")
# plt.xlabel("Ages")
# plt.ylabel("Median Salary (USD)")

# plt.tight_layout()

# plt.show()





# import matplotlib.pyplot as plt

 
# courses = ['History', 'Art', 'Math', 'English']
# for index, item in enumerate(courses, start = 2):
#     print(index, item)
# print('Helloworld')
# x = np.linspace(-5, 5, 100) # Create a list of evenly-spaced numbers over the range
# var = 5*np.sin(x)
# plt.plot(x, var , 'r--', label = 'cos(x)')   
# # plt.plot(x, x*x*x-1)    # Plot the sine of each x point
# plt.plot(x, np.cos(x), 'b', label = 'cos(x)')
# plt.xlabel('x-Axis')
# plt.ylabel('y-Axis')
# plt.title('Functions')
# plt.legend()
# plt.show() 
