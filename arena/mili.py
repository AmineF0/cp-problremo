import math
t = int(input())
for _ in range(t):
    q = int(input())
    print(
        math.ceil((math.sqrt(4*q)-1)/2)
    )