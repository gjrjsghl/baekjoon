n = int(input())

k = []
for i in range(n):
    k.append(int(input()))
arr = [0]*(n+10)

k.append(0)
k.append(0)
k.append(0)

arr[0] = k[0]
arr[1] = k[0]+k[1]
arr[2] = max(k[0]+k[2],k[1]+k[2])

for i in range(3,n):
    arr[i] = max(arr[i-2],k[i-1]+arr[i-3])+k[i]
print(arr[n-1])