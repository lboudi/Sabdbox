# -*- coding: utf-8 -*-

import numpy as np
from math import sin
import matplotlib.pyplot as plt

N = 41
K = 20
    
X = np.zeros((N,1))
Y_hat = np.zeros((N,1))
Y = np.zeros((N,1))

cpt = -20.0
for i in range(41):
    X[i,0] = cpt
    cpt += 1.0
for i in range(20):
    Y_hat[i,0] = sin(X[i,0])/X[i,0]
Y_hat[20,0] = 1.0 # Prolongement par continuité
for i in range(21,41,1):
    Y_hat[i,0] = sin(X[i,0])/X[i,0]
    
M = np.zeros((N,K))
for i in range(N):
    for j in range(K):
        M[i,j] = X[i,0]**j

A = np.matmul(np.transpose(M),M)
a = np.matmul(2*np.linalg.inv(A),np.matmul(np.transpose(M),Y_hat))
for i in range(N):
    somme = 0.0
    for j in range(K):
        somme += a[j,0]*(X[i,0]**j)
    Y[i,0] = somme
    somme = 0.0

x = list(X)
y = list(Y)
y_hat = list(Y_hat)
plt.plot(x,y)
plt.plot(x,y_hat)
plt.show()
        
