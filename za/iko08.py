n=int(input())
ma=dict()
re=range(100010)
f=1
def inft(x):
  global f
  if x in ma:
    return ma[x]
  else:
    ma[x]=f
    f=f+1
    return f-1

def fint(m):
  while m!=re[m] :
    m=re[m] 
  return m

def combine(x,y):
  x1=fint(x)
  y1=fint(y)
  if x1!=y1 :
    re[x1]=y1

for i in range(n):
  t=raw_input().split()
  if t[0]=='1' :
    if fint(inft(t[1]))!=fint(inft(t[2])) :
      print("no")
    else :
      print("yes")
  if t[0]=='0' :
    combine(inft(t[1]),inft(t[2]))
