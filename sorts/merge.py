def merge(a,l,r):
    tmp=[None for i in range(r-l)]
    pos1=pos2=0
    m=(l+r)//2
    while l+pos1<m and m+pos2<r:
        if a[l+pos1]<a[m+pos2]:
            tmp[pos1+pos2]=a[l+pos1]
            pos1+=1
        else:
            tmp[pos1+pos2]=a[m+pos2]
            pos2+=1
    while l+pos1<m:
        tmp[pos1+pos2]=a[l+pos1]
        pos1+=1
    while m+pos2<r:
        tmp[pos1+pos2]=a[m+pos2]
        pos2+=1
    for i in range(r-l):
        a[l+i]=tmp[i]

def mergesort(a,l, r):
    if l+1>=r:
        return
    mergesort(a,l,(l+r)//2)
    mergesort(a,(l+r)//2,r)
    merge(a,l,r)

def main():
    global a
    a=list(map(int,input().split()))
    n=len(a)
    mergesort(a,0,n)
    print(a)

main()