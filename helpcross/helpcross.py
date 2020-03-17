inRange = lambda num, bottom, top: bottom <= num and num <= top

infile = open('helpcross.in')
text = infile.readlines()
infile.close()

chickenNum, initial = text[0][:-1].split(' ')
chickenNum, initial = int(chickenNum), int(initial)

chickens = [int(text[i][:-1]) for i in range(1, chickenNum + 1)]
cows = [[int(j) for j in text[i][:-1].split(' ')] for i in range(chickenNum + 1, chickenNum + initial + 1)]

slots = dict(zip(chickens, [[] for i in range(chickenNum)]))
for i in chickens:
    for j in cows:
        if inRange(i, *j):
            slots[i] += [j]
slots = {k:v for k, v in slots.items() if len(v) > 0}

answer = 0

outfile = open('helpcross.out', 'w')
outfile.write(str(answer))
outfile.close()
