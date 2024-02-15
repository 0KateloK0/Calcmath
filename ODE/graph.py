import matplotlib.pyplot as plt
import numpy as np

a = []
with open('iter', 'r') as f:
    a = np.array([list(map(float, x.split())) for x in f.read().split('\n')[:-1]], np.double)

x = np.linspace(0, 2.452, num=10000)
plt.plot(x, np.sinh(x) / np.sinh(1) - 2 * x)
# plt.plot(x, -x + 2 * np.exp(x) - 1)
plt.plot(x, a[::, 0])
plt.show()