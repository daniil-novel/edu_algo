V_SIZE = 3

class Vertex:

    def __init__(self, index):
        self.index = index

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


def init():
    filename = "data.txt"
    f = open(filename)

    t_string = int(f.readline()) # считает и удалит пробелы на концах строки
    print(t_string)

    vertex_list = []
    edge_list = []

    for i in range(t_string):
        word = f.readline().strip()
        pvs = word[:V_SIZE] # возьмет субстроку от текущей поз. размера V_SIZE

        for j in range(1, len(word) - V_SIZE + 1): # -1 не нужен
            vs = word[j:j + V_SIZE]

            v = Vertex(vs)
            pv = Vertex(pvs)
            vertex_list.append(v)

            edge = Edge(pv, v) # первое старт (исп конструктор, pvs не надо созд ранее), второе финиш
            edge_list.append(edge)

            pvs = vs

    f.close()

    vertex_list.sort()
    edge_list.sort()

#    print(vertex_list)
    print(*edge_list, sep = "\n")

    return vertex_list, edge_list


def uniqueVertexCount(vertex_list):
    k = 0
    pv = None
    for v in vertex_list:
#        print(v, "", end ="")
        if pv != v:
            k += 1

        pv = v

    return k

def uniqueEdgeCounter(edge_list):
    unique_edge_list = []
    pe = None
    for e in edge_list:
        if pe != e:
            unique_edge_list.append(e)
        else:
            unique_edge_list[-1].weight += 1

        pe = e

    return unique_edge_list

def main():
    #alg7v2.py
    vertex_list, edge_list = init()

    print(uniqueVertexCount(vertex_list))
    
    unique_edge_list = uniqueEdgeCounter(edge_list)
    
    print(len(unique_edge_list))
    print(*unique_edge_list, sep = "\n")
    
main()
