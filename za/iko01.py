a=int(input())
b=set((raw_input().split()))
t=1
while t>0 :
  if str(t) in b :
    t=t+1
  else :
    break
print(t)
