import numpy as np

row = column = 2 
print("enter admittance matrix(Ytr): ")
  
entries = list(map(str, input().split()))

Ytr = np.array(entries, dtype=complex).reshape(row, column)

C = (abs(Ytr[1, 0] * Ytr[0, 1])) / (2 * Ytr[0, 0].real * Ytr[1, 1].real - (Ytr[1, 0] * Ytr[0, 1]).real)
print('\n\nC = %f\n\n' %C)

if(Ytr[0, 0].real > 0 and Ytr[1, 1].real > 0 and (C >= 0 and C <= 1)):
    print('stable')
else:
    print('unstable')

#2.7+6.8j 0-0.5j 53-22j 0.1+1.5j