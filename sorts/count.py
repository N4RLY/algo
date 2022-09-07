a=list(map(int,input().split()))
k=len(a)
b=[]
cnt=[0 for i in range(k)]
for i in a:
    cnt[i]+=1
for i in range(k):
    for j in range(cnt[i]):
        b.append(i)
    