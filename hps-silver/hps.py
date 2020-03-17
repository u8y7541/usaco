from collections import Counter
infile = open('hps.in')
outfile = open('hps.out', 'w')
answer = 0
text = infile.readlines()[1:]
m = Counter(text).most_common(1)[0][0]
last = ''.join(text).rfind(m)
answer += text.count(m)

try:
    m = Counter(text[last + 1:]).most_common(1)[0][0]
    last = ''.join(text[last + 1:]).rfind(m)
    answer += text[last + 1:].count(m)
except:
    answer += 1
print(answer)
outfile.write(str(answer) + '\n')
outfile.close()
infile.close()
