n,k = list(map(int,input().split()))

a = set()
for i in range(n):
    a.add(input())
c = []
for j in range(k):
    b = input()
    if b in a:
        c.append(b)
c.sort()

print(len(c))
for i in c:
    print(i)