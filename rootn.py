import numpy as np
import matplotlib.pyplot as plt

# Define the range of n
n = np.linspace(1, 100, 400)

# Compute the values of the functions
sqrt_n = np.sqrt(n)
n_log_n = n * np.log(n)

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n, sqrt_n, label=r'$\sqrt{n}$', color='blue')
plt.plot(n, n_log_n, label=r'$n \log n$', color='red')

# Add labels and title
plt.xlabel('n')
plt.ylabel('Function Value')
plt.title('Graph of $n \log n$ and $\sqrt{n}$')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
