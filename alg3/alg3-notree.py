ifilename = "alg3-data.txt" 
ifo = open(ifilename)

n = int(next(ifo))
print("n =", n)

depth = [0] + [-1] * n
#print(depth)

max_depth = 0
deepest_leaf_index = 0

for i in range(1, n):
    pi = int(next(ifo))
    depth[i] = depth[pi] + 1
    if depth[i] > max_depth:
        max_depth = depth[i]
        deepest_leaf_index = i


print(deepest_leaf_index)
