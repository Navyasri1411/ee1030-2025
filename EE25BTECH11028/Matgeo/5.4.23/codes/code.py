import numpy as np
import matplotlib.pyplot as plt

# Define matrix A and its inverse
A = np.array([[2, -3],
              [-1, 2]])
A_inv = np.array([[2, 3],
                  [1, 2]])

# Define unit square vertices
square = np.array([[0, 0],
                   [1, 0],
                   [1, 1],
                   [0, 1],
                   [0, 0]])  # closed polygon

# Apply transformations
square_A = square @ A.T
square_Ainv = square @ A_inv.T

# Plotting
plt.figure(figsize=(7, 7))
plt.plot(square[:,0], square[:,1], 'k--', label="Original Square")
plt.plot(square_A[:,0], square_A[:,1], 'r-', label="Transformed by A")
plt.plot(square_Ainv[:,0], square_Ainv[:,1], 'b-', label="Transformed by A⁻¹")

# Style
plt.axhline(0, color='gray', lw=0.5)
plt.axvline(0, color='gray', lw=0.5)
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()
plt.title("Effect of Matrix A and its Inverse on the Unit Square")
plt.grid(True)
plt.savefig("fig11.png")
plt.show()