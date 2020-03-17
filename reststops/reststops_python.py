fin = open('reststops.in')
data = [[int(j) for j in i.split()] for i in fin.readlines()]
fin.close()
(L, N, F, B) = (data[0][0], data[0][1], data[0][2], data[0][3])
stops = list(enumerate([[0, 0]] + data[1:]))

#def recurse(curStop, tastiness):
#	if (curStop == stops[-1]):
#		return tastiness
#	target = max(stops[curStop[0]+1:], key = lambda a: a[1][1])
#	return recurse(target, tastiness+(target[1][0]-curStop[1][0])*(F-B)*(target[1][1]))

curStop = (0, [0, 0])
tastiness = 0
diff = F-B
while curStop != stops[-1]:
	target = max(stops[curStop[0]+1:], key = lambda a: a[1][1])
	tastiness+=(target[1][0]-curStop[1][0])*diff*(target[1][1])
	curStop = target


fout = open('reststops.out', 'w')
#fout.write(str(recurse((0, [0, 0]), 0)))
fout.write(str(tastiness))
fout.close()
