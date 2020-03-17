fin = open('censor.in')
data = fin.readlines()
fin.close()
S = data[0][:-1]
T = data[1][:-1]

while T in S:
	S = S.replace(T, '')

fout = open('censor.out', 'w')
fout.write(S)
fout.close()
