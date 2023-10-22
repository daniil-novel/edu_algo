f = open('data.txt')
n, x, t = map(int, f.readline().split())
print(n, x, t)
a = list(map(int, f.readline().split()))
print(a)
b = [abs(ai - x) for ai in a]
print(b)
bb = list(enumerate(b, 1))
print(bb)
bbs = sorted(bb, key = lambda x: x[1])
print(bbs)
k = 0
for i, bi in bbs:
    t -= bi
    if t < 0: break
    k += 1;

print(k)
for j in range(k):
    print(bbs[j][0], end = ' ')

print()
