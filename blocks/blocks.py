def nonrepeats(*args):
    a = args[0]
    b = args[1]
    c = {len(a):a, len(b):b}
    small = c[min(c)]
    big = (args[0] if small==args[1] else args[1])
    for i in small:
        if i in big:
            big = big.replace(i, '', 1)
    return small + big
f = open(input())
text = [i[:-1] for i in f.readlines()]
text = ''.join([nonrepeats(*(i.split(' '))) for i in text[1:]])
f.close()
alpha = 'abcdefghijklmnopqrstuvwxyz'
answer = [str(text.count(alpha[i])) for i in range(26)]
o = open('blocks.out', 'w')
o.write('\n'.join(answer))
o.close()
