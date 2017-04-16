import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

# Antes de usar esto, tirar en consola "./tp1 1 -exp > resEj1.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

# arr = np.genfromtxt("rsalida.txt", delimiter=',')
arr = np.loadtxt("salida_exp1a_ej5.data", delimiter=',')
tiempo    = [row[0] for row in arr] #tiempo en MS
n         = [row[1] for row in arr] #P
m         = [row[2] for row in arr] #P
mochila   = [row[3] for row in arr] #P
dist      = [row[4] for row in arr] #P
visitados = [row[5] for row in arr] #P


def promedio(list):
   return sum(list)/len(list)

def graph(formula, x_range):
    x = np.array(x_range)
    y = eval(formula)
    return y

def factorial(list):
    res = []
    for number in list:
      res.append(math.factorial(number))
    return res

k = 0
promedioTiempoBT = []
nMasmBT = []
while k < 180:
  subList = tiempo[k:k+30]
  promedioTiempoBT.append(promedio(subList))
  nMasmBT.append(m[k])
  k += 30


promedioTiempoEj2 = []
nMasm = []
while k < 1830:
  subList = tiempo[k:k+150]
  promedioTiempoEj2.append(promedio(subList))
  nMasm.append(m[k])
  k += 150

promedioTiempoEj3 = []
while k < len(tiempo):
  subList = tiempo[k:k+30]
  promedioTiempoEj3.append(promedio(subList))
  k += 30


promedio1NP = np.array(promedioTiempoBT)
promedio2NP = np.array(promedioTiempoEj2)
promedio3NP = np.array(promedioTiempoEj3)
nmBT = np.array(nMasmBT)
nm = np.array(nMasm)

print(len(promedio3NP))
print(len(nm))


fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
# pylab.plot(nmBT, promedio1NP,color='red', marker='o', label= '4 GYM')
pylab.plot(nm, promedio2NP,color='blue', marker='D', label= '5 GYM')
pylab.plot(nm, promedio3NP,color='green', marker='>', label= '6 GYM')


ax1.set_title("Tiempo segun cantidad de gimnasios")
ax1.set_xlabel('Cantidad de pokeparadas')
# ax1.set_xscale('linear')
ax1.set_ylabel('Tiempo de procesamiento en ns')
# ax1.set_yscale('linear')
# ax1.autoscale(enable=True, axis='both', tight=None)

leg = ax1.legend()

leg = plt.legend( loc = 'upper left')

plt.show()
