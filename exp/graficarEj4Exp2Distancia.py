import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

# Antes de usar esto, tirar en consola "./tp1 1 -exp > resEj1.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

# arr = np.genfromtxt("rsalida.txt", delimiter=',')
arr = np.loadtxt("salida_exp2_ej4.txt", delimiter=',')
tiempo    = [row[0] for row in arr] #tiempo en MS
#n         = [row[1] for row in arr] #P
#m         = [row[2] for row in arr] #P
#mochila   = [row[3] for row in arr] #P
dist      = [row[1] for row in arr] #P
limite      = [row[2] for row in arr] #P

#visitados = [row[5] for row in arr] #P


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
promedioDist = []
limites = []
while k < len(dist):
  subList = dist[k:k+50]
  promedioDist.append(promedio(subList))
  limites.append(limite[k])
  k += 50


promedio1NP = np.array(promedioDist[0:98])
promedio2NP = np.array(promedioDist[99:197])
promedio3NP = np.array(promedioDist[198:296])
promedio4NP = np.array(promedioDist[297:395])
nm = np.array(limites[0:98])


cota = 'factorial(x)*x*x*x'
deAUno = range(1,8)
grafCota = graph(cota, deAUno)
deAUno = np.array(deAUno)

# medianaX  = mediana(x)
# modaX     = moda(x)


fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(nm, promedio1NP,'red', marker='o', label= 'P = 1, RCL = 5, V = A')
pylab.plot(nm, promedio3NP,'green', marker='^', label= 'P = 1, RCL = 5, V = B')



fig2 = plt.figure()
fig2.patch.set_facecolor('white')
ax2 = fig.add_subplot(111)
pylab.plot(nm, promedio2NP,'blue', marker='*', label= 'P = 2, RCL = 5, V = A')
pylab.plot(nm, promedio4NP,'black', marker='.', label= 'P = 2, RCL = 5, V = B')

#pylab.plot(deAUno, grafCota,color='black', marker='s', label= 'Cota de Complejidad')


ax1.set_title("Distancia para distintas configuraciones con Criterio 1")
ax1.set_xlabel('i de criterio de parada')
ax1.set_ylabel('Distancia')

ax2.set_title("Distancia para distintas configuraciones con Criterio 2")
ax2.set_xlabel('i de criterio de parada')
ax2.set_ylabel('Distancia')
# ax1.set_xscale('linear')
# ax1.set_yscale('linear')
# ax1.autoscale(enable=True, axis='both', tight=None)

leg = ax1.legend()
leg = plt.legend( loc = 'upper right')

leg2 = ax2.legend()
leg2 = plt.legend( loc = 'upper right')
plt.show()
