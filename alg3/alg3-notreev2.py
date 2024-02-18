ifilename = "alg3-data.txt" 
ifo = open(ifilename)

n = int(next(ifo))
print("n =", n)

depth = [0] + [-1] * n
#print(depth)

for i in range(1, n):
    pi = int(next(ifo))
    depth[i] = depth[pi] + 1

deepest_leaf_index = max(range(len(depth)), key = depth.__getitem__)

print(deepest_leaf_index)
