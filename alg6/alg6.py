class Curb:
    def __init__(self):
        self.take_day = 0
        self.put_day = 0
        self.id = 0
        self.sad = 0

def init(curb_list, sorted_curb_list, m_delta, n_take):
    filename = "datav2.txt"

    f = open(filename, 'r')
    k_curb = int(f.readline())
    n_take, m_put = map(int, f.readline().split())
    print(f"{k_curb} {n_take} {m_put}")

    m_delta[0] = m_put

    for i in range(k_curb):
        curb = Curb()
        curb.take_day, curb.id = map(int, f.readline().split())
        curb_list.append(curb)
        sorted_curb_list.append(curb)

    sorted_curb_list.sort(key=lambda x: x.id)

    f.close()


def main():
    curb_list = []
    sorted_curb_list = []
    m_delta = [0]
    n_take = 0

    init(curb_list, sorted_curb_list, m_delta, n_take)

    summ_sad = 0
    curb_id = 0

    for i in range(n_take):
        scl = sorted_curb_list[i]

        if scl.id != curb_id:
            curb_id = scl.id
            scl.put_day = scl.take_day
        else:
            scl.put_day = sorted_curb_list[i - 1].take_day

        scl.sad = scl.take_day - scl.put_day
        summ_sad += scl.sad

        if m_delta[0] > 0:
            m_delta[0] -= 1

        print(scl)

    print(summ_sad)
