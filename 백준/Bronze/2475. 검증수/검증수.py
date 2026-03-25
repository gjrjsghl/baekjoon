a = list(map(int,input().split()))

k = 0
for i in a:
    k += i**2
print(k%10)