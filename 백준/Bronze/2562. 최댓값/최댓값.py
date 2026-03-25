
a = [0,0]
for i in range(1,10):
    k = int(input())
    if a[0] < k:
        a[0] = k
        a[1] = i
print(a[0])
print(a[1])