fin = open('homework.in')
data = fin.readlines()
fin.close()
N = int(data[0][:-1])
q = [int(i) for i in data[1].split(' ')]

s = sum(q)
partial=0
avgs=[0]*(N-1)
for i in range(1, N-1):
	partial+=q[i-1]
	avgs[i-1] = (s-partial-min(q[i:]))/(N-i-1)
print(avgs)

#def computeAvg(K):
#	return sum([i for i in q[K:] if i != min(q[K:])])/(N-K-1)

#avgs = [computeAvg(i) for i in range(1, N-1)]
maxAvg = max(avgs)
fout = open('homework.out', 'w')
for i in range(1, N-1):
	if avgs[i-1]==maxAvg:
		fout.write(str(i))
fout.close()
