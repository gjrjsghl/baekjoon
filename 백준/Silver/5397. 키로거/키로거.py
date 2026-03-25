import sys
from collections import deque

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    front = deque()
    back = deque()
    a = input()
    for i in a:
        if i.isalpha() or i.isdigit():
            front.append(i)
        if i == '-':
            if front:
                front.pop()
        if i == '<':
            if front:
                back.appendleft(front.pop())
        if i == '>':
            if back:
                front.append(back.popleft())
    front.extend(back)
    print("".join(front))