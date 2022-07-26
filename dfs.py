#список смежностей
#O(n+m)
#dfs
def dfs(v):
  used[v]=1
  for u in g[v]:
    if not used[u]:
      dfs(u)
#ввод
n,m=map(int, input().split())
g=[[]for i in range(n+1)]
used=[0 for i in range(n+1)]
for i in range(m):
  v,u=map(int, input().split())
  g[u].append(v)
  g[v].append(u)
for i in range(1,n):
    if not used[i]:
        dfs(i)
        #cnt+=1 - компоненты связности



#таблица смежностей
#O(n^2)
def dfs(v):
    used[v]=1
    for i in range(n):
        if not g[v][i] or used[i]:
            continue
        dfs(i)

#input
n,m=map(int, input().split())
g=[[0 for i in range(n+1)] for i in range(n+1)]
used=[0 for i in range(n+1)]
for i in range(m):
    v,u=map(int,input().split())
    g[v][u]=1
    g[u][v]=1