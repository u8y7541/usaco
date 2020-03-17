fin = open('shuffle.in')
data = fin.readlines()
fin.close()
N = int(data[0][:-1])
a = [int(i) for i in data[1][:-1].split(' ')]

def followPath(index):
	visited = [index]
	while a[visited[-1]]-1 not in visited:
		visited.append(a[visited[-1]]-1)
	return (a[visited[-1]]-1 == index)

fout = open('shuffle.out', 'w')
fout.write(str(sum([followPath(i) for i in range(N)])))
fout.close()
