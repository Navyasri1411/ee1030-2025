import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load compiled C library
# For Linux/Mac
lib = ctypes.CDLL('./libmatrix_inverse.so')
# For Windows:
# lib = ctypes.CDLL('matrix_inverse.dll')

# Define argument types
lib.inverse2x2.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double)]

# Input matrix A = [[2, -3], [-1, 2]]
A = np.array([2.0, -3.0, -1.0, 2.0], dtype=np.float64)
A_inv = np.zeros(4, dtype=np.float64)

# Call C function to get inverse
lib.inverse2x2(A.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
               A_inv.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))

# Reshape to 2x2 matrices
A_matrix = A.reshape(2, 2)
A_inv_matrix = A_inv.reshape(2, 2)

print("Original matrix A:")
print(A_matrix)
print("Inverse matrix A⁻¹ (from C):")
print(A_inv_matrix)

# Define the unit square
square = np.array([
    [0, 0],
    [1, 0],
    [1, 1],
    [0, 1],
    [0, 0]
])

# Apply transformations
square_A = square @ A_matrix.T
square_Ainv = square @ A_inv_matrix.T

# Plot
plt.figure(figsize=(8, 6))
plt.plot(square[:, 0], square[:, 1], 'k--', linewidth=1.5, label='Original Square')  # Black dashed
plt.plot(square_A[:, 0], square_A[:, 1], color='orange', linewidth=2.5, label='Transformed by A')  # Orange
plt.plot(square_Ainv[:, 0], square_Ainv[:, 1], color='green', linewidth=2.5, label='Transformed by A⁻¹')  # Green

# Optional: add markers to show square corners
plt.scatter(square[:, 0], square[:, 1], color='black')
plt.scatter(square_A[:, 0], square_A[:, 1], color='orange')
plt.scatter(square_Ainv[:, 0], square_Ainv[:, 1], color='green')

plt.grid(True)
plt.gca().set_aspect('equal', adjustable='box')
plt.title('Effect of Matrix A and its Inverse on the Unit Square')
plt.legend()
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.tight_layout()
plt.show()
