import sys

input = sys.stdin.readline


n = int(input())


num = []
k = 0
for i in range(n):
    a = int(input())
    num.append(a)
    k += a

num.sort()


z = []

if n !=1:
    for i in range(n):
        if num[i] != num[i-1]:
            z.append([num[i],1])
        else:
            z[-1][1] += 1

    z = sorted(z,key=lambda x : x[1],reverse=True)
else: z = [[num[0],1]]

print(round(k/n))
print(num[n//2])
if(n > 1 and z[0][1] == z[1][1]):
    print(z[1][0])
else: print(z[0][0])
print(max(num)-min(num))