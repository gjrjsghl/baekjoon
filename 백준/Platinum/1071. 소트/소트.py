n = int(input())

k = list(map(int,input().split()))

num = [0]*1001

sortNum = []

for i in k:
    num[i] += 1
    if i not in sortNum:
        sortNum.append(i)


sortNum.sort()

while len(sortNum) != 0:
    if (len(sortNum) > 1 and sortNum[1] != sortNum[0]+1) or len(sortNum) == 1:
        print((str(sortNum[0])+' ')*num[sortNum[0]],end ='')
        del sortNum[0]
    elif len(sortNum) > 2:
        print((str(sortNum[0])+' ')*num[sortNum[0]],end ='')
        print(sortNum[2],end = ' ')
        num[sortNum[2]] -= 1
        if num[sortNum[2]] == 0:
            del sortNum[2]
        del sortNum[0]
    else:
        print(sortNum[1],end = ' ')
        num[sortNum[1]] -= 1
        if num[sortNum[1]] == 0:
            del sortNum[1]
        


