from sympy import Symbol
from sympy.solvers import solve
def dx(x):
    xd=14*x[0]+2*x[1]+1
    return xd
def dy(x):
    yd=2*x[0]+10*x[1]-10
    return yd
x=[0,0]
xp=[0,0]
df=[0,0]
dfp=[0,0]
for i in range(10):
    a=Symbol('a')
    df[0]=dx(x)
    df[1]=dy(x)
    xp[0]-=a*df[0]
    xp[1]-=a*df[1]
    dfp[0]=dx(xp)
    dfp[1]=dy(xp)
    u=solve(dfp[0],a)
    uu=solve(dfp[1],a)
    if uu<u:
        if uu>[0]:
            a=uu
        else:
            a=u
    else:
        if u>[0]:
            a=u
        else:
            a=uu
print(a)