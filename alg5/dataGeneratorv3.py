from random import randint, sample
from itertools import pairwise

nmax = 10 ** 5 
kmax = 10 ** 5 
pimax = 10 ** 5 
ssmax = 10 ** 6
nfile = 9 

def gen_randint_list_with_limited_sum(count, limit):
    borders = [0] + sorted(sample(range(1, limit), count))
    return [y - x for x, y in pairwise(borders)]


for i in range(2, nfile + 1):
    filename = f"data{i}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    k = randint(1, kmax)
    print(n, k, file = f)

    for i in range(k):
        pi = randint(1, pimax)
        print(pi, file = f, end = " ")
    
    print(file = f)

    s = gen_randint_list_with_limited_sum(n, ssmax)

    for i in range(0, n):
        r = randint(1, n)
        
        print(r, s[i], file = f, end = " ")
    
        list_prog_id = sample(range(1, k + 1), s[i])

        print(*list_prog_id, file = f)


    f.close()
    print("Создан файл", filename)

