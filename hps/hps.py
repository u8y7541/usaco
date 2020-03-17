from collections import Counter
def isValid(rules):
    return len(rules) == len(set(rules.values()))
infile = open('hps.in')
outfile = open('hps.out', 'w')
rules = {}
answer = 0
text = [i[:-1] for i in infile.readlines()[1:] if i[0] != i[2]]
origLen = len(text)

for i in range(3):
    if text == []:
        break
    common, num = Counter(text).most_common(1)[0] 
    rules[int(common[0])] = int(common[2])

    # Filters
    text = list(filter(common.__ne__, text))
    answer += origLen - len(text)
    text = list(filter(''.join(list(reversed(common))).__ne__, text))
    text = list(filter(lambda x: x[0] != common[0], text))
    text = list(filter(lambda x: x[2] != common[2], text))

    print(text)
    origLen = len(text)
outfile.write(str(answer) + '\n')
print(rules)
infile.close()
outfile.close()
