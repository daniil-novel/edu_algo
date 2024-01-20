from random import randint

nmax = 10 ** 5 
kmax = 10 ** 5 
pimax = 10 ** 5 
nfile = 9

def gen_uniq_rand_values(count, min_value, max_value):
    unique_values = set()
    while len(unique_values) < count:
        random_value = randint(min_value, max_value)
        unique_values.add(random_value)
    
    return list(unique_values)


for i in range(2, nfile + 1):
    filename = f"data{i}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    print(n, "", file = f, end = "")

    k = randint(1, kmax)
    print(k, file = f)

    for i in range(0, k):
        pi = randint(1, pimax)
        print(pi, "", file = f, end = "")
    
    print(file = f)

    for i in range(0, n):
        r = randint(1, n)
        s = randint(1, nmax)
        
        print(r, "", file = f, end = "")
        print(s, "", file = f, end = "")
    
        list_prog_id = gen_uniq_rand_values(s, 1, k)

        print(*list_prog_id, " ", file=f)


    f.close()
    print("Создан файл", filename)

