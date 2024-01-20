from random import choice, randint, random
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
        for _ in range(length):
            bukva = choice(string.ascii_lowercase)
            word = ''.join(bukva)
            print(word, file = f, end = '', sep = '')