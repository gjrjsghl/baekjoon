n = input()

cnt = [0]*10

def gogo(num):

    while len(num) > 0 and num[0] == '0' :
        num = num[1:]
    
    if len(num) == 1:
        for i in range(1,int(num)+1):
            cnt[i] += 1
        #print(num)
        return

    if len(num) == 0:
        return
    
    size = len(num)

    goal = str(int(num[0])-1)+'9'*(size-1)    
    goal = str(int(goal))

    if len(goal) == 1:
        for i in range(1,int(goal)+1):
            cnt[i] += 1
    
    else:

        size = len(goal)-1
        c = size*(10**(size-1))

        #print(goal)
        #print('\t',c)

        for i in range(0,int(goal[0])+1):
            if i !=0:
                cnt[i] += int(goal[1:])+1
            for j in range(1,10):
                cnt[j] += c

        #print(int(num[0]),int(num[1:])+1)
    cnt[int(num[0])] += int(num[1:])+1

    gogo(num[1:])

gogo(n)


size = len(n)
z = 0
for i in range(1,size):
    z += int('9'*i)
#print(z)

total = size*int(n)-z

cnt[0] += total-sum(cnt)

for i in cnt:
    print(i, end =' ')
