infile = open('maxcross.in')
text = infile.readlines()
infile.close()

n,k,b = text[0][:-1].split(' ')
n,k,b = int(n),int(k),int(b)

l = [0] * n
[l.__setitem__(int(text[i][:-1]) - 1, 1) for i in range(1, b+1)]

answers = []
for i in range(n - k + 1):
    if l[i] == 0:
        answers.append(l[i:i + k].count(1))

outfile = open('maxcross.out', 'w')
outfile.write(str(min(answers)))
outfile.close()
