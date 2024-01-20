from collections import deque, Counter

V_SIZE = 3

class Vertex(str): pass
class Edge(tuple): pass

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
        pv = Vertex(''.join(w))

        vertex_set.add(pv)
        
        for ch in word[V_SIZE:]:
            w.append(ch)

            v = Vertex(''.join(w))
            vertex_set.add(v)

            edge = Edge((pv, v))
            edge_list.append(edge)

            pv = v

    f.close()

    return vertex_set, Counter(edge_list)

def main():
    #alg7v2.py
    vertex_set, edge_dict = init()

    print(len(vertex_set))
    print(len(edge_dict))

    for edge, weight in edge_dict.items():
        print(f"{edge[0]} {edge[1]} {weight}")

#    print(dict(edge_dict))

main()
