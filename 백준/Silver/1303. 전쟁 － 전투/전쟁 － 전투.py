n,m = list(map(int,input().split()))


xy = []

for i in range(m):
    z = list(input())
    xy.append(z)


def dfs(a,b,f):
    if a < 0 or b < 0 or a >= m or b >= n: return 0
    if (xy[a][b] == 'W' and f == 1) or (xy[a][b] == 'B' and f == 0): return 0
    if xy[a][b] == 0: return 0

    xy[a][b] = 0
    return 1 + dfs(a-1,b,f) + dfs(a+1,b,f) + dfs(a,b+1,f) + dfs(a,b-1,f)


b = 0
w = 0
for i in range(n):
    for j in range(m):
        if xy[j][i] == 'B':
            b += (dfs(j,i,1))**2
        if xy[j][i] == 'W':
            w += (dfs(j,i,0))**2
print(w,b)

