import os
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Clase_28.dat")

plt.figure(1, figsize=(10,5)) 
plt.plot(data[:,1], data[:,3],label=(" With air resistance "),c='green')
plt.plot(data[:,5], data[:,6],label=(" Ideal "),c='red')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')
plt.savefig("friccion.png")