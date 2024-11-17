import numpy as np
from numpy import *


rows = int(input("请输入矩阵的行、列数 "))
columns = rows
matrix = []
for i in range(rows):
    row = list(map(int, input(f"Enter row {i+1} values separated by spaces: ").split()))
    matrix.append(row)
print("The matrix is:")


try:
    print(matrix)
    B=np.linalg.inv(matrix)
except:
    print("矩阵不存在逆矩阵")
else:
    print(B)