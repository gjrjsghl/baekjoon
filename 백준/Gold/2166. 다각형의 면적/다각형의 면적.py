def solve():
    n = int(input())
    
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = map(int,input().split())
        xs.append(x)
        ys.append(y)
    
    xs.append(xs[0])
    ys.append(ys[0])
    
    sum1 = 0
    sum2 = 0
    
    for i in range(n):
        sum1 += xs[i] * ys[i+1]
        sum2 += ys[i] * xs[i+1]
    
    area = abs(sum1 - sum2) / 2
    
    print(f"{area:.1f}")

solve()