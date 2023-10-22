from random import randint

nmax = 2 * 5
kmax = 2 * 5
cimax = 5
rimax = 5
simax = 5
nfile = 9 

for f in range(3, nfile + 1):
    filename = f"alg2-data{f}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    print(n, file = f)

    for i in range(0, n):
        ci = randint(0, cimax)
        print(ci, "", file = f, end = "")

    print(file = f)
    
    for r in range(0, n):
        ri = randint(1, rimax)
        print(ri, "", file = f, end = "")

    print(file = f)

    k = randint(1, kmax)
    print(k, file = f)

    for j in range(0, k):
        si = randint(0, simax)
        print(si, "", file = f, end = "")

    print()

    f.close()
    print("Создан файл", filename)




