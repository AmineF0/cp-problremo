i=int(input())

while i>9:
    cnt=str(i)
    cnt = [int(g) for g in cnt]
    i = sum(cnt)
    
print(i)