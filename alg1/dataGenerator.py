from random import randint

nmax = 2 * 10**5
xmax = 10**9 
tmax = 3 * 10**14 
amax = 10**9
nfile = 9 

for i in range(1, nfile + 1):
    filename = f"data{i}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    x = randint(0, xmax)
    t = randint(0, tmax)
    print(n, x, t, file = f)

    for j in range(0, n):
        a = randint(1, amax)
        print(a, "", file = f, end = "")
    
    print()
    
    f.close()
    print("Создан файл", filename)

