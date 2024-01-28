from random import choices, randint, random, shuffle

nmax = 5# * 10**4
mmax = 10# * 10**4
kmax = 15# * 10**4

nfile = 5

for f in range(2, nfile + 1):
    filename = f"data{f}.txt"
    f = open(filename, "w")

    n = randint(1, nmax)
    m = randint(1, mmax)
    k = randint(1, kmax)
    print(n, m, k, file=f)

    edge_list = set()

    for _ in range(m):
        u, v = randint(1, n), randint(1, n)

        attempts = 0
        max_attempts = 10 * n  # Защита от бесконечных циклов

        while u == v or (u, v) in edge_list or (v, u) in edge_list:
            u = randint(1, n)
            v = randint(1, n)
            attempts += 1
            if attempts > max_attempts:
                raise RuntimeError("Не удалось сделать уникальное ребро.")
        edge_list.add((u, v))

    operations = ["ask"] * (k - len(edge_list))+ ["cut"] * len(edge_list)
    shuffle(operations)

    for u, v in edge_list:
        print(u, v, file=f)

    for operation in operations:
        if operation == "ask":
            u, v = randint(1, n), randint(1, n)
            print(f"{operation} {u} {v}", file=f)
        elif operation == "cut":
            u, v = edge_list.pop()
            print(f"{operation} {u} {v}", file=f)

    f.close()

    print("Создан файл", filename)

