from math import inf
from itertools import groupby, pairwise

class Dig:
    def __init__(self):
        self.day = 0
        self.walk_id = 0

def init():
    filename = "datav3.txt"

    f = open(filename)
    k_walk, n_dig, m_repair = map(int, f.readline().split())
    print(k_walk, n_dig, m_repair)

    dig_list = []

    m_count = m_repair

    for i in range(n_dig):
        dig = Dig()
        dig.day, dig.walk_id = map(int, f.readline().split())
        dig_list.append(dig)

    dig_list.sort(key = lambda x: x.walk_id)

    f.close()

    return dig_list, m_count


def main():
    sad_list = []
    m_count = 0

    dig_list, m_count = init()
    
    for walk_id, dig_gen in groupby(dig_list, key = lambda x: x.walk_id):
        sad_list.append(inf)
        sad_list += (dig.day - pdig.day for pdig, dig in pairwise(dig_gen))

    sad_list.sort(reverse = 1)

    sad_list_tail = sad_list[m_count:]
    sum_sad = sum(sad_list_tail)

    print(sum_sad if sum_sad < inf else -1)

main()
