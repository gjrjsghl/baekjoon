a,b = list(map(str,input().split()))

k = 0
if a == b:
    for i in a:
        if i == '8':
            k += 1

else:
    if len(a) != len(b):
        k = 0
    
    else:
        for i in range(len(a)):
            if a[i] == b[i]:
                if a[i] == '8':
                    k += 1
            else:
                break
print(k)