import matplotlib
import matplotlib.pyplot as pyplot
import numpy as np

arr1 = list()
arr2 = list()
point = input("Enter No of points :")
for i in range (int (point)):
    s = input()
    li = s.split()
    x = arr1.append(int (li[0]))
    y = arr2.append(int (li[1]))
slope = []
intercept = []
xval1 = []
xval2 = []
f = open('C:/Users/BEJJANKI ADITYA/Desktop/DAA_run/sample.txt','r')
for row in f:
    row = row.split(' ')
    slope.append(float(row[0]))
    intercept.append(float(row[1]))
    xval1.append(float(row[2]))
    xval2.append(float(row[3]))
le = len(slope)
for w in range (int (le)):
    po = np.linspace(xval1[w],xval2[w],50)
    pyplot.plot(po, slope[w] * po + intercept[w],linestyle='solid')
  # print(slope[w])
  #  print(intercept[w])
  #  print('\n')
    pyplot.plot()
pyplot.xlabel('x - axis')
pyplot.ylabel('y - axis')
pyplot.scatter(arr1, arr2, label= "Points", color= "black")
pyplot.title('Visualization with points and lines')
pyplot.legend()
pyplot.show()