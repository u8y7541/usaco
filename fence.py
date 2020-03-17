def pointInTriangle(n, m, x, y):
    return x * m/n > y

n = int(input())
m = int(input())
p = int(input())
answer = 0
for y in range(m):
    for x in range(p):
        if pointInTriangle(n, m, x, y):
            beginning = x
            break
    for x in range(p - 1, 0, -1):
        if pointInTriange(n, m, x, y):
            end = x
            break
    answer += end - beginning
print(answer)
