from random import randint, sample
from itertools import pairwise

nmax = 10 ** 4 
rmax = 10 ** 9 
cmax = 10 ** 9
nfile_max = 9 + 1
nfile_min = 6

for i in range(nfile_min, nfile_max):
    filename = f"data{i}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    print(n, file = f)

    for i in range(n):
        r = randint(-rmax, rmax)
        c = randint(-cmax, cmax)
        print(r, c, file = f)

    print(file = f)

    f.close()
    print("Создан файл", filename)

