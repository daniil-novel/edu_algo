from random import choices, randint, random, shuffle

nmax = 10**6

nfile_begin = 3
nfile_end = 9

for f in range(nfile_begin, nfile_end + 1):
    filename = f"data{f}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    print(n, file=f)

    for _ in range(n):
        print(random.choice(['A', 'B']), file=f)
        
