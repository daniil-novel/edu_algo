from random import choices, randint, random
import string

nmax = 4 * 10 ** 4
nfile = 3

for f in range (2, nfile + 1):
    filename = f"data{f}.txt"
    f = open(filename, "w")

    t = randint(1, nmax)
    print(t, file = f)

    for i in range(t):
        length = randint(4, 30)
        word = ''.join(choices(string.ascii_lowercase, k = length))
        print(word, file = f)
