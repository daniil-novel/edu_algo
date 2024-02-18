class Node: 
    def appendChild(self, child):
        child.parent = self
        child.depth = self.depth + 1


class Tree:
    def __init__(self, size):
        self.size = size
        self.max_depth = 0
        self.deepest_leaf = None
        self.nodes = [Node() for i in range(size)]
        self.root = self.nodes[0];
        self.root.depth = 0;
        

filename = "alg3-data.txt"
f = open(filename)

n = int(next(f))
print("n =", n)

tr = Tree(n + 1)

for i in range(1, n):
    nd = tr.nodes[i]
    nd.index = i

    pi = int(next(f))
    tr.nodes[pi].appendChild(nd)

    if nd.depth > tr.max_depth:
        tr.max_depth = nd.depth;
        tr.deepest_leaf = nd;

print(tr.deepest_leaf.index)




