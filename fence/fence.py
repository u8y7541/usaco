def pointInTriangle(n, m, p, x, y):
	if x > n:
		return x * -m/(p-n) > y
	return x * m/n > y

n = int(input())
m = int(input())
p = int(input())
answer = 0
for y in range(m):
	for x in range(p):
		if pointInTriangle(n, m, p, x, y):
			beginning = x
		break
	for x in range(p - 1, 0, -1):
		if pointInTriangle(n, m, p, x, y):
			end = x
		break
	answer += end - beginning
print(answer)
