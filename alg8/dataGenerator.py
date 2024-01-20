from random import choices, randint, random
import string

nmax = 50
mmax = 100
kmax = 150

nfile = 3

for f in range (1, nfile + 1):
    filename = f"data{f}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    m = randint(1, mmax)
    k = randint(1, kmax)
    print(n, m, k, file = f)

    for i in range(m):
        u = randint(1, n)
        v = randint(1, n)    
        print(u, v, file = f)

    for i in range(k):
        cmd = "ask"
        u = randint(1, n)
        v = randint(1, n)    
        print(cmd, u, v, file = f)
        cmd = "cut"
    
    f.close()
    print("Создан файл", filename)

