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
distanciaPromedios = []
while k < len(dist): #dist = 160*30*15
  subList = x[k:k+30]
  promedioDist.append([promedio(subList),grasp[k]]) #Promedio dist = 160*15
  k += 30

aux2 = 0
aux = 40*15 - 1
primerConfig = promedioDist[aux2:aux2+aux]
aux2 = aux + 1
segundaConfig = promedioDist[aux2:aux2+aux]
aux2 = aux + 1
terceraConfig = promedioDist[aux2:aux2+aux]
aux2 = aux + 1
cuartaConfig = promedioDist[aux2:aux2+aux]

h = 0
while h < len(promedioDist)



cota = 'factorial(x)*x*x*x'
deAUno = range(1,8)
grafCota = graph(cota, deAUno)
deAUno = np.array(deAUno)

# medianaX  = mediana(x)
# modaX     = moda(x)


fig = plt.figure()
fig.patch.set_facecolor('white')
ax1 = fig.add_subplot(111)
pylab.plot(nm, promedio1NP,'red', marker='o', label= 'P = 1, i = 100, V = A')
pylab.plot(nm, promedio2NP,'blue', marker='*', label= 'P = 2, i = 100, V = A')
pylab.plot(nm, promedio3NP,'green', marker='^', label= 'P = 1, i = 100, V = B')
pylab.plot(nm, promedio4NP,'black', marker='D', label= 'P = 2, i = 100, V = B')
pylab.plot(nm, promedio5NP,'green', marker='D', label= 'Backtracking')

#pylab.plot(deAUno, grafCota,color='black', marker='s', label= 'Cota de Complejidad')


ax1.set_title("Distancia para distintas configuraciones")
ax1.set_xlabel('Tamaño de vértices que acceden a la RCL')
# ax1.set_xscale('linear')
ax1.set_ylabel('Distancia')
# ax1.set_yscale('linear')
# ax1.autoscale(enable=True, axis='both', tight=None)

leg = ax1.legend()

leg = plt.legend( loc = 'upper left')

plt.show()
