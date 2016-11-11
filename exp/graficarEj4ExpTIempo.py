import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

# Antes de usar esto, tirar en consola "./tp1 1 -exp > resEj1.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

# arr = np.genfromtxt("rsalida.txt", delimiter=',')
arr = np.loadtxt("salida_exp1_ej4.txt", delimiter=',')
tiempo    = [row[0] for row in arr] #tiempo en MS
#n         = [row[1] for row in arr] #P
#m         = [row[2] for row in arr] #P
#mochila   = [row[3] for row in arr] #P
dist      = [row[1] for row in arr] #P
grasp      = [row[2] for row in arr] #P

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
promedioTiempo = []
graspes = []
while k < len(tiempo):
  subList = tiempo[k:k+100]
  promedioTiempo.append(promedio(subList))
  graspes.append(grasp[k])
  k += 100


promedio1NP = np.array(promedioTiempo[0:15])
promedio2NP = np.array(promedioTiempo[16:31])
promedio3NP = np.array(promedioTiempo[32:47])
promedio4NP = np.array(promedioTiempo[48:63])
nm = np.array(graspes[0:15])


cota = 'factorial(x)*x*x*x'
deAUno = range(1,8)
grafCota = graph(cota, deAUno)
deAUno = np.array(deAUno)

# medianaX  = mediana(x)
# modaX     = moda(x)


fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(nm, promedio1NP,'red', marker='o', label= 'P = 1, i = 100, Vecindario A')
pylab.plot(nm, promedio2NP,'blue', marker='*', label= 'P = 2, i = 100, Vecindario A')
pylab.plot(nm, promedio3NP,'green', marker='^', label= 'P = 1, i = 100, Vecindario B')
pylab.plot(nm, promedio4NP,'black', marker='D', label= 'P = 2, i = 100, Vecindario B')

#pylab.plot(deAUno, grafCota,color='black', marker='s', label= 'Cota de Complejidad')


ax1.set_title("Tiempo para distintas configuraciones")
ax1.set_xlabel('Tamaño de vértices que acceden a la RCL')
# ax1.set_xscale('linear')
ax1.set_ylabel('Tiempo de procesamiento en ns')
# ax1.set_yscale('linear')
# ax1.autoscale(enable=True, axis='both', tight=None)

leg = ax1.legend()

leg = plt.legend( loc = 'lower right')

plt.show()
