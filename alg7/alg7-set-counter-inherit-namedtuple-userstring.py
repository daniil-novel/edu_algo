from collections import deque, Counter, namedtuple, UserString

V_SIZE = 3

class Vertex(UserString):
    def __init__(self, obj):
        super().__init__("".join(obj))

Edge = namedtuple('Edge', "start, finish")

class EdgeDict(Counter):
    def __str__(self):
        s = ""
        for edge, weight in self.items():
            s += f"{edge.start} {edge.finish} {weight}\n"
        return s

def init():
    filename = "data.txt"
    f = open(filename)

    word_count = int(f.readline()) # считает и удалит пробелы на концах строки
    print(word_count)

    vertex_set = set()
    edge_list = []

    for _ in range(word_count):
        word = f.readline().strip()

        w = deque(word[:V_SIZE], V_SIZE)
        pv = Vertex(w)

        vertex_set.add(pv)
        
        for ch in word[V_SIZE:]:
            w.append(ch)

            v = Vertex(w)
            vertex_set.add(v)

            edge = Edge(pv, v)
            edge_list.append(edge)

            pv = v

    f.close()

    return vertex_set, EdgeDict(edge_list)

def main():
    #alg7v2.py
    vertex_set, edge_dict = init()

    print(len(vertex_set))

    print(len(edge_dict))
    print(edge_dict)

main()
