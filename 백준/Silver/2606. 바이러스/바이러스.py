n = int(input())
k = int(input())


v = [0 for i in range(n+1)]
n = [[] for i in range(n+1)]

for i in range(k):
    a,b = list(map(int,input().split()))
    n[a].append(b)
    n[b].append(a)


c = 0
def dfs(a):
    if v[a] == 1: return
    v[a] = 1
    global c
    c += 1
    for i in n[a]:
        dfs(i)
dfs(1)

print(c-1)