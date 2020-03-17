infile = open('cownomics.in')
outfile = open('cownomics.out', 'w');
data = [i[:-1] for i in infile.readlines()[1:]]
infile.close()
predictors = 0
for i in range(len(data[0])):
    predicting = []
    for j in range(int(len(data)/2)):
        predicting += [(data[0][i] == data[j][i])]
    if all(predicting):
        predicting = []
        for j in range(int(len(data)/2), len(data)):
            predicting += [(data[0][i] != data[j][i])]
        if all(predicting):
            predictors += 1 
outfile.write(str(predictors))
outfile.close()
