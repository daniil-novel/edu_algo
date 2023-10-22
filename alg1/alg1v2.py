ifilename = 'data6.txt'
ofilename = 'out-p6.txt'

ifo = open(ifilename)
n, x, t = map(int, ifo.readline().split())
print(n)

a = map(int, ifo.readline().split())
b = [abs(ai - x) for ai in a]
bb = list(zip(b, range(1, len(b) + 1)))

#print(bb)
bb.sort()
#print(bb)

k = 0
for bi, i in bb:
    t -= bi
    if t < 0: break
    k += 1;

ofo = open(ofilename, 'w')

print(k, file = ofo)
for j in range(k):
    print(bb[j][1], end = ' ', file = ofo)

print(file = ofo)

ofo.close()
ifo.close()
