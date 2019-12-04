import numpy as np
import matplotlib.pylab as plt

#Me guie de estas paginas para relaizar la sumatoria
#https://www.nayuki.io/res/how-to-implement-the-discrete-fourier-transform/dft.py
#https://www.nayuki.io/page/how-to-implement-the-discrete-fourier-transform
    

def fourier(x):
    n = len(x)
    result = np.ones(n,dtype=complex)
    for i in range(n):  # For each result element
        result[i] = complex(0)
        for t in range(n):  # For each input element
            formula = 2.0j * np.pi * t * i / n
            result[i] += x[t] * np.exp(-1.0*formula)
            
    tam=len(result)
    norm=result/tam
    
    return tam,norm

def F1(w,t):
    f1=3*np.cos(w*t) + 2*np.cos(3*w*t) + np.cos(5*w*t)
    return f1

n=51
T=2*np.pi
h=T/n
t=np.linspace(0,50*h,n)
w=2*np.pi/T

tam,val=fourier(F1(w,t))
tf=np.linspace(0,tam,tam)

plt.figure(1,figsize=(14,5))

plt.subplot(1,2,1)
plt.plot(t,F1(w,t))
plt.scatter(t,F1(w,t),s=9)
plt.xlabel('t')
plt.ylabel('y(t)')

plt.subplot(1,2,2)
plt.stem(tf,abs(val),use_line_collection=True)
plt.xlabel('k')
plt.ylabel('|X|/N')

plt.savefig('1.png')