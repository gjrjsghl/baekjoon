a,b = list(map(int,input().split()))


f = 0

while b <= 100:
    k = (a/b)-(a//b) 
    if k == 0:
        if b%2 == 0:
            b += 1
        else:

            if a//b - b//2 < 0:
                b += 1
                continue
            f = 1
            for i in range(b):
                print(a//b-b//2+i,end =" ")
            break
    elif k == 0.5:
        if b%2 == 0:


            if a//b - b//2 +1 < 0:
                b += 1
                continue
            
            f = 1
            for i in range(b):
                print(a//b-b//2+1+i,end = " ")
            break
        else:
            b += 1
    else:
        b += 1
if f == 0:
    print("-1")