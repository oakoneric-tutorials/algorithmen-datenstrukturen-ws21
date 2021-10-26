import numpy as np
import matplotlib.pyplot as plt

a = 0.5
b = 0
c = -0.5

f = lambda x: a*x**2 + b*x + c
f_prime = lambda x: 2 * a * x + b
Phi = lambda x: x - (f(x) / f_prime(x))

root = - b / (2*a) + np.sqrt((b / (2*a))**2 - c/a)
print("root = ", root)

x = np.linspace(0,3,100)
y = f(x)
p = Phi(x)

ax = plt.gca()
plt.title('Fixpunktiteration zur Nullstellensuche von $g(x) = 0.5x^2 - 0.5$')
ax.spines['left'].set_position('zero')
ax.spines['bottom'].set_position('zero')
ax.spines['top'].set_color('none')
ax.xaxis.tick_bottom()
ax.spines['right'].set_color('none')
ax.xaxis.tick_bottom()

ax.plot(x,y)
ax.scatter(root, 0)

erg = np.zeros(10)
erg[0] = 2.8
for i in range(len(erg)-1):
    erg[i+1] = Phi(erg[i])

print("Iterationen: \n", erg)

for i in range(len(erg) - 1):
    ax.plot([erg[i], erg[i]], [0, f(erg[i])], c='black', linewidth=1)
    ax.plot([erg[i], erg[i+1]], [f(erg[i]), 0], c='black', linewidth=1, linestyle='--')
    if i < 3:
        ax.annotate(f'$x_{i}$', (erg[i], -0.2), fontsize=11)

plt.savefig('tut03_fixpunktiteration.png', bbox_inches='tight', dpi=300, transparent=True)