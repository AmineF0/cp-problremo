n = int(input())

dic = {}

for _ in range(n):
    d = input().strip().split(',')
    dic[d[0]] = d[1]

n = int(input())

arr = []
dics = {}

for _ in range(n):
    d = input().strip().split(',')
    dics[d[1]] = d[0]
    arr.append(d[1])

arr.sort()

k=0
for num in arr:
    if num in dic.keys():
        print(f"{num},{dic[num]},{dics[num]}")
        k+=1

if k==0: print('nomatch')