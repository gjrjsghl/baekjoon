n = int(input())
splitAlp = set()
if n != 0:
    splitAlp = set(input().split())

m = int(input())
splitNum = set()
if m != 0:
    splitNum = set(input().split())

k = int(input())
nonSplit = set()
if k != 0:
    nonSplit = set(input().split())

s = int(input())
S = input()

f = 1
for i in S:
    if i in splitAlp and i not in nonSplit:
        if f == 0:
            print()
            f = 1
        continue
    if i in splitNum and i not in nonSplit:
        if f == 0:
            print()
            f = 1
        continue
    if i == ' ':
        if f == 0:
            print()
            f = 1
        continue
    f=0
    print(i, end = '')

