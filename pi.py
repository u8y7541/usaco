def p(r):
    t=0
    x=0
    y=r
    for i in range(r+1):
        a=i
        b=(r**2-a**2)**0.5
        t+=((a-x)**2+(b-y)**2)**0.5
        x=a
        y=b
    print(2*t/r)
p(10**7)