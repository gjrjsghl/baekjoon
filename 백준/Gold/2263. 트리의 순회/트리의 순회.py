import sys


sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())


inorder = list(map(int,input().split()))
postorder = list(map(int,input().split()))
inpos = [0 for _ in range(n+1)]


for i in range(n):
    inpos[inorder[i]] = i

def findTree(s,e,ps,pe):
    if s > e or ps  > pe: return

    root = postorder[pe]
    rootidx = inpos[root]

    print(root,end = ' ')


    left = rootidx-s
    findTree(s,rootidx-1,ps,ps+left-1)
    findTree(rootidx+1,e,ps+left,pe-1)

findTree(0,n-1,0,n-1)