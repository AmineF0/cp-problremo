n = int(input())

def HalfRoundUp(value):
    return int(value + 0.5)

for i in range(n):
  mx = 0
  d= 1
  q = int(input())
  while d<q*10:
    r = HalfRoundUp(q/d)*d
    if r>mx:
      q = r
      mx = r
    d*=10
  print(mx)