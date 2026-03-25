n,k = map(int,input().split())

num = list(map(int,input().split()))
num.insert(0,0)
for i in range(1,n+1):
    num[i] += num[i-1]
#print(num)
for i in range(k):
    a,b = map(int,input().split())
    print(num[b]-num[a-1])

