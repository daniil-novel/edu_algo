from collections import deque
from itertools import groupby

V_SIZE = 3

class Vertex:

    def __init__(self, index):
        if isinstance(index, str):
            self.index = index
        else:
            self.index = "".join(index)

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
        self.weight = 1

    def __repr__(self):
        return f"{self.start.index} -> {self.finish.index}: {self.weight}"

    def __lt__(self, other):
        if self.start < other.start:
            return 1
        elif other.start < self.start:
            return 0
        return self.finish < other.finish

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

    vertex_list = []
    edge_list = []

    for _ in range(word_count):
        word = f.readline().strip()

        w = deque(word[:V_SIZE], V_SIZE)
        pv = Vertex(w)
        for ch in word[V_SIZE:]:
            w.append(ch)

            v = Vertex(w)
            vertex_list.append(v)

            edge = Edge(pv, v)
            edge_list.append(edge)

            pv = v

    f.close()

    vertex_list.sort()
    edge_list.sort()

    print(*edge_list, sep = "\n")

    return vertex_list, edge_list


def uniqueVertexCount(vertex_list):
    return sum(1 for v, g in groupby(vertex_list))
    

def uniqueEdgeCounter(edge_list):
    unique_edge_list = []

    for e, g in groupby(edge_list):
        e1 = e.copy()
        e1.weight = sum(1 for edge in g)

        unique_edge_list.append(e1)

    return unique_edge_list

def main():
    #alg7v2.py
    vertex_list, edge_list = init()

    print(uniqueVertexCount(vertex_list))
    
    unique_edge_list = uniqueEdgeCounter(edge_list)
    
    print(len(unique_edge_list))
    print(*unique_edge_list, sep = "\n")
    
main()
