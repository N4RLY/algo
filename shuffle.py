def f(a,c,n):
    global ans
    if len(a)==n:
        ans+=[(''.join(a))]
    c2=c.copy()
    for i in c2:
        c.remove(i)
        f(a+[i],c,n)
        c+=[i]
def shuffle(s):
    s=str(s)
    global ans
    ans=[]
    dig=[]
    a=[]
    dig=list(i for i in s)
    f(a,dig,len(s))
    return ans
print(shuffle(1234))