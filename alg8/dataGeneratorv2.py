from random import choices, randint, random, shuffle

nmax = 5 * 10**4
mmax = 10 * 10**4
kmax = 15 * 10**6

nfile_begin = 9
nfile_end = 10

for f in range(nfile_begin, nfile_end + 1):
    filename = f"data{f}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    m_ = min(mmax, n * (n - 1) // 2)
    m = randint(1, m_) if m_ > 0 else 0 
    k = randint(m, kmax)
    print(n, m, k, file=f)

    edge_list = set()

    while len(edge_list) < m:
        u = randint(1, n)
        v0 = randint(1, n)
        for v_ in range(v0, n + v0):
            v = (v_ - 1) % n + 1
            if u != v and (u, v) not in edge_list and (v, u) not in edge_list:
                edge_list.add((u, v))
                break


    operations = ["ask"] * (k - len(edge_list))+ ["cut"] * len(edge_list)
    shuffle(operations)

    for u, v in edge_list:
        print(u, v, file=f)

    for operation in operations:
        if operation  == "ask":
            u, v = randint(1, n), randint(1, n)
            print(f"{operation} {u} {v}", file=f)
        elif operation == "cut":
            u, v = edge_list.pop()
            print(f"{operation} {u} {v}", file=f)

    f.close()

    print("Создан файл", filename)

