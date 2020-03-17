f = open('cowsignal.in')
text = f.readlines()
print(text)
text[0] = text[0].split(' ')
multiplier = int(text[0][-1])
o = open('cowsignal.out', 'w')
lastline = ''
for i in text[1:]:
    for j in i[:-1]:
        print(j, end='')
        o.write(j * multiplier)
        lastline += j * multiplier
    o.write('\n')
    for j in range(multiplier - 1):
        o.write(lastline + '\n')
    print()
    lastline = ''
f.close()
o.close()
