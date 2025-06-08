# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Définir la grille
x = np.linspace(-3, 3, 100)
y = np.linspace(-3, 3, 100)
X, Y = np.meshgrid(x, y)

# Calculer la fonction
Z = np.exp(-X**2 - Y**2)

# Création de la figure
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Tracer la surface
ax.plot_surface(X, Y, Z, cmap='viridis')

# Ajouter des étiquettes
ax.set_title("f(x, y) = exp(-x² - y²)")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("f(x, y)")

plt.show()

