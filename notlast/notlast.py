infile = open('notlast.in')
outfile = open('notlast.out', 'w')
try:
    text = infile.readlines()[1:]
    d = {"Bessie": 0, "Elsie": 0, "Daisy": 0, "Gertie": 0, "Annabelle": 0, "Maggie": 0, "Henrietta": 0}
    for i in [j.split(' ') for j in text]:
        if i[0] in d:
            d[i[0]] += int(i[1][:-1])
            continue
        d[i[0]] = int(i[1][:-1])
    infile.close()
    search = list(d.values())[:]
    search = list(filter(min(search).__ne__, search))
    m = min(search)
    answers = [i for i in d if d[i] == m]
    if len(answers) != 1:
        outfile.write("Tie\n");
    else:
        outfile.write(answers[0] + '\n')
    outfile.close()
except:
    outfile.write("Tie\n")
    outfile.close()
    infile.close()
    exit()

