from collections import deque, defaultdict

V_SIZE = 3

class Vertex:
    def __init__(self, index):
        if isinstance(index, str):
            self.index = index
        else:
            self.index = "".join(index)

    def __hash__(self):
        return hash(self.index)

    def __repr__(self):
        return self.index

    def __lt__(self, other): #аналог переопределения оператора <, возвращает bool
        return self.index < other.index

    def __eq__(self, other): # перегруз сравнения
        if other is None: return 0
        return self.index == other.index

class Edge:
    def __init__(self, start, finish):
        self.start = start
        self.finish = finish

    def __repr__(self):
        return f"{self.start} -> {self.finish}"

    def __lt__(self, other):
        if self.start < other.start:
            return 1
        elif other.start < self.start:
            return 0
        return self.finish < other.finish

    def __hash__(self):
        return hash(self.start) ^ hash(self.finish)

    def __eq__(self, other): # перегруз сравнения
        if other is None: return 0
        return self.start == other.start and self.finish == other.finish

    def copy(self):
        return Edge(self.start, self.finish)


def init():
    filename = "data.txt"
    f = open(filename)

    word_count = int(f.readline()) # считает и удалит пробелы на концах строки
    print(word_count)

    vertex_set = set()
    edge_dict = defaultdict(int)

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
            edge_dict[edge] += 1

            pv = v

    f.close()

    return vertex_set, edge_dict

def main():
    #alg7v2.py
    vertex_set, edge_dict = init()

    print(len(vertex_set))
    print(len(edge_dict))

    for edge, weight in edge_dict.items():
        print(f"{edge.start} {edge.finish} {weight}")

#    print(dict(edge_dict))

main()
