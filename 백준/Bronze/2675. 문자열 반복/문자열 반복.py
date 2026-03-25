n = int(input())

for i in range(n):
    a,b = input().split()

    for i in b:
        print(i*int(a),end = '')
    print()