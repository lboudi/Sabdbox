import numpy as np


def Identite(A,N,T):
    
    Somme = np.zeros((T,T))
    for i in range(N):
        pi = 1
        for k in range(i):
            pi*=(i - k)
        for j in range(N):
            pj = 1
            for l in range(j):
                pj*=(j - l)
            Somme += (((-1.0)**j)/(pi*pj))*np.linalg.matrix_power(A,i+j)
    return Somme

A = np.array([[0,1],[0.125,0.25]])
print("Voici A = \n")
print(A)
M = Identite(A,10,2)
print("Voici M = \n")
print(M)

            
            
        
    
    
