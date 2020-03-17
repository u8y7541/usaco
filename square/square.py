from math import ceil
f = open('square.in')
text = [i.split(' ') for i in f.readlines()]
f.close()
#try:
text = [[int(j) for j in i] for i in text]
#except:
#    print("Inputs invalid!")
#    exit()
#if any([any([False if j in range(11) else True for j in i]) for i in text]):
#    print("Inputs invalid!")
#    exit()
#answer = [text[0][0] - text[1][2], text[0][2] - text[1][0],
#          text[0][2] - text[1][2], text[0][1] - text[1][1], text[0][1] - text[1][3],
#          text[0][3] - text[1][1], text[0][3] - text[1][3]]
#answer = max([abs(i) for i in answer])**2
answer = max([max([abs(text[0][2] - text[1][0]), abs(text[0][0] - text[1][2])]),
          max([abs(text[0][1] - text[1][3]), abs(text[0][3] - text[1][1])])]) ** 2
o = open('square.out', 'w')
o.write(str(answer))
o.close()
