def checkValid(text, answer, limit):
    before = text[:answer+1]
    after = text[answer+1:]
    total = 0
    while True:
        m = min(before)
        prevLen = len(before)
        before = list(filter(lambda x: x != 0, map(lambda x: x-m, before)))
        zeroAmt = prevLen - len(before)
        total += m
        for i in range(zeroAmt):
            m = min(after)
            after.remove(m)
            before.append(m)
        if total > limit:
            return False
        elif len(before) == 0:
            return True

infile = open('cowdance.in')
outfile = open('cowdance.out', 'w')
text = infile.readlines()
n, maxtime = text[0][:-1].split(' ')
n, maxtime = int(n), int(maxtime)
text = [int(i[:-1]) for i in text[1:]]
answer = n - 1

for i in range(n):
    if checkValid(text, answer, maxtime):
        answer -= 1
    else:
        answer += 1
        break

infile.close()
outfile.write(str(answer) + '\n')
outfile.close()
