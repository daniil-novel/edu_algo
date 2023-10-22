from random import randint

nmax = 10 ** 5
nfile = 9

for f in range (1, nfile + 1):
    filename = f"alg3-data{f}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    print(n, file = f)

    for i in range(0, n):
        repo_num_i = randint(0, i)
        print(repo_num_i, file = f)
    
    f.close()
    print("Создан файл", filename)
