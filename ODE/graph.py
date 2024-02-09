import matplotlib.pyplot as plt
import numpy as np

a = []
with open('rk', 'r') as f:
    a = np.array([list(map(float, x.split())) for x in f.read().split('\n')[:-1]], np.double)

x = np.linspace(0, 1, num=51)
plt.plot(x, -x + 2 * np.exp(x) - 1)
plt.plot(x, a[::, 0])
plt.show()