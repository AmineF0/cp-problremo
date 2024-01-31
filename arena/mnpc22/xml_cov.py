n, q = [int(i) for i in input().split()]

ms = {}
ma = {}

for i in range(n):
    s = input().strip()
    arr = s.split('/')
    
    for l in range(1,len(arr)):
        if arr[l-1] in ms.keys():
            ms[arr[l-1]]+=1
        else:
            ms[arr[l-1]]=1
        arr[l] = arr[l-1] +'/'+ arr[l]
        
    if arr[len(arr)-1] in ms.keys():
        ms[arr[len(arr)-1]]+=1
    else:
        ms[arr[len(arr)-1]]=1
        
for i in range(q):
    que = input().split()
    op = int(que[0])
    
    if op==1:
        arr = que[1].strip().split('/')
        for l in range(1,len(arr)):
            if arr[l-1] in ma.keys():
                ma[arr[l-1]]+=1
            else:
                ma[arr[l-1]]=1
            arr[l] = arr[l-1] +'/'+ arr[l]
        
        if arr[len(arr)-1] in ms.keys():
            ms[arr[len(arr)-1]]+=1
        else:
            ms[arr[len(arr)-1]]=1
    else :
        s = que[1].strip()
        if s in ma.keys():
            d = ma[s]/ms[s]
            print(f'{d:.6f}')
        else : print(0)
        
    