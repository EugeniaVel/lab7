def m24(a,x,n):
    if n==2:
        nm=0
        for i in range(n):
            nm+=a[i]*x[i]
    elif n==4:
        nm=[]
        for j in range(2):
            nmm=0
            for i in range(2):
                nmm+=a[i][j]*x[i]
            nm.append(nmm)
    return nm
def ff(x):
    f=10*x[0]**2+3*x[0]*x[1]+x[1]**2+10*x[1]
    return f
def df(x,n):
    if n==0:
        f=20*x[0]+3*x[1]
    else:
        f=3*x[0]+2*x[1]+10
    return f
def lyam(a,d,g):
    niz=m24(a,d,4)
    nizz=m24(niz,d,2)
    l=-(m24(g,d,2))/nizz
    return l
a=[[20,3],[3,2]]
x=[1,1]
d=[]
g=[]
for i in range(2):
    g.append(df(x,i))
    d.append(-df(x,i))
for i in range(4):
    ly=lyam(a,d,g)
    for j in range(2):
        x[j]=x[j]+d[j]*ly
    for j in range(2):
        g[j]=df(x,j)
        if g[j]==0:
            break
    verh=m24(a,g,4)
    niz=m24(a,d,4)
    b=m24(verh,d,2)/m24(niz,d,2)
    for j in range(2):
        d[j]=-g[j]+b*d[j]
print("Минимум функции:"+str(ff(x)))