class Node:
    def __init__(self, index = 0, depth = 0):
        self.index = index;
        self.depth = depth;
        self.parent = None;
        
class Tree:
    def __init__(self, size):
        self.size = size
        self.max_depth = 0
        self.deepest_leaf = None
        self.nodes = [Node() for i in range(size)]
        self.root = self.nodes[0];
        

filename = "alg3-data.txt"
f = open(filename)

n = int(next(f))
print("n =", n)

tr = Tree(n + 1)

for i in range(1, n):
    nd = tr.nodes[i]
    nd.index = i

    pi = int(next(f))
    pnd = tr.nodes[pi]
    nd.parent = pnd
    nd.depth = pnd.depth + 1

    if nd.depth > tr.max_depth:
        tr.max_depth = nd.depth;
        tr.deepest_leaf = nd;

print(tr.deepest_leaf.index)




