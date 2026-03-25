n = list(map(int,input().split()))

z = []
for i in range(n[0]):
    a = input()
    z.append(a)


ans = ''
c = 0

for i in range(n[1]):
    cnt = [[0,3],[0,2],[0,1],[0,0]] #ACGT
    for j in range(n[0]):
        if z[j][i] == 'A': cnt[0][0] += 1
        if z[j][i] == 'C': cnt[1][0] += 1
        if z[j][i] == 'G': cnt[2][0] += 1
        if z[j][i] == 'T': cnt[3][0] += 1
    cnt.sort(reverse=1)
    if cnt[0][1] == 3: ans += 'A'
    if cnt[0][1] == 2: ans += 'C'
    if cnt[0][1] == 1: ans += 'G'
    if cnt[0][1] == 0: ans += 'T'

    c += n[0]-cnt[0][0]
    
print(ans)
print(c)