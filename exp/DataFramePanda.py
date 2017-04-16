import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys
import pandas as pd

# Antes de usar esto, tirar en consola "./tp1 1 -exp > resEj1.txt". CUIDADO CON PISAR EL ARCHIVO ANTERIOR

# arr = np.genfromtxt("rsalida.txt", delimiter=',')
BL = np.loadtxt("salida_exp1a_ej5_BL.data", delimiter=',')
BT = np.loadtxt("salida_exp1a_ej5_BT.data", delimiter=',')
GR = np.loadtxt("salida_exp1a_ej5_GR.data", delimiter=',')
tiempoBL    = [row[0] for row in BL] #tiempo en MS
distBL      = [row[4] for row in BL] #P
visitadosBL = [row[5] for row in BL] #P

tiempoBT    = [row[0] for row in BT] #tiempo en MS
distBT      = [row[4] for row in BT] #P
visitadosBT = [row[5] for row in BT] #P

tiempoGR    = [row[0] for row in GR] #tiempo en MS
distGR      = [row[4] for row in GR] #P
visitadosGR = [row[5] for row in GR] #P


dataBL = pd.DataFrame([tiempoBL, distBL, visitadosBL], columns=["Tiempo", "Distancia", "Estaciones visitadas"])
dataBT = pd.DataFrame([tiempoBT, distBT, visitadosBT], columns=["Tiempo", "Distancia", "Estaciones visitadas"])
dataGR = pd.DataFrame([tiempoGR, distGR, visitadosGR], columns=["Tiempo", "Distancia", "Estaciones visitadas"])
dataBL.describe()
