n, k = map(int, input().split()) #k-number
a = list(map(int, input().split()))
a.sort()
l = 0
r = n

while r - l > 1:
    m = (r + l) // 2
    if a[m]<=k:
        l = m
    else:
        r = m
print(l)