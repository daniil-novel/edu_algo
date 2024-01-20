from math import inf

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
    
    pdig = Dig()
    for dig in dig_list:
        if dig.walk_id == pdig.walk_id:
            sad_list.append(dig.day - pdig.day)
        else:
            sad_list.append(inf)

        pdig = dig

    sad_list.sort(reverse = 1)

    sum_sad = 0
    for sad in sad_list:
        if m_count:
            m_count -= 1
        elif sad == inf:
            sum_sad = -1
            break
        else:
            sum_sad += sad

    print(sum_sad)

main()
