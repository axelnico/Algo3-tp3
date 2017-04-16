import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

# Antes de usar esto, tirar en consola "./tp1 1 -exp > resEj1.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

# arr = np.genfromtxt("rsalida.txt", delimiter=',')
arr = np.loadtxt("salida_exp1-2.data", delimiter=',')
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
promedioTiempoNporM = []
nMasm = []
while k < len(tiempo)/3:
  subList = tiempo[k:k+30]
  promedioTiempoNporM.append(promedio(subList))
  nMasm.append(m[k] + n[k])
  k += 30

promedioTiempoSumPocionesNecesarias = []
while k < (len(tiempo)/3)*2:
  subList = tiempo[k:k+30]
  promedioTiempoSumPocionesNecesarias.append(promedio(subList))
  k += 30

promedioTiempo3porN = []
while k < len(tiempo):
  subList = tiempo[k:k+30]
  promedioTiempo3porN.append(promedio(subList))
  k += 30


promedio1NP = np.array(promedioTiempoNporM)
promedio2NP = np.array(promedioTiempoSumPocionesNecesarias)
promedio3NP = np.array(promedioTiempo3porN)
nm = np.array(nMasm)


cota = 'factorial(x)*x'
deAUno = range(2,17)
grafCota = graph(cota, deAUno)
deAUno = np.array(deAUno)

# medianaX  = mediana(x)
# modaX     = moda(x)

fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(nm, promedio1NP,color='red', marker='o', label= 'n*m')
pylab.plot(nm, promedio2NP,color='green', marker='<', label= 'cantidad de pociones exactas')
pylab.plot(nm, promedio3NP,color='blue', marker='v', label= '3*n')
# pylab.plot(deAUno, grafCota,color='black', marker='s', label= 'Cota de Complejidad')


ax1.set_title("Tiempo segun tamaño de la mochila")
ax1.set_xlabel('Cantidad de gimnasios + pokeparadas')
# ax1.set_xscale('log')
ax1.set_ylabel('Tiempo de procesamiento en ns')
ax1.set_yscale('log')
# ax1.autoscale(enable=True, axis='both', tight=None)

leg = ax1.legend()

leg = plt.legend( loc = 'upper left')

plt.show()
