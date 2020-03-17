def toggle(grid, x, y):
    grid[y][x] = 1 - grid[y][x]
def toggleRect(grid, x, y):
    for i in range(y + 1):
        for j in range(x + 1):
            toggle(grid, j, i)
infile = open('cowtip.in')
outfile = open('cowtip.out', 'w')
grid = [[int(j) for j in list(i[:-1])] for i in infile.readlines()[1:]]
answer = 0
broken = False
while any([any(i) for i in grid]):
    for y in range(len(grid) - 1, -1, -1):
        for x in range(len(grid) - 1, -1, -1):
            if grid[y][x] == 1:
                answer += 1
                toggleRect(grid, x, y)
                broken = True
                break
        if broken:
            broken = False
            break
outfile.write(str(answer) + '\n')
infile.close()
outfile.close()
