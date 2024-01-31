n=int(input())
while n:
  L,v,l,r=[int(i) for i in input().split()]
  nbr_lan = (L)//v
  
  nbr_r = (r)//v
  nbr_l = (l-1)//v

  print(nbr_lan-nbr_r+nbr_l)

  n-=1