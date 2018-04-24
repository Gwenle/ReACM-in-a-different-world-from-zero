def zhishu(m):
 i=2
 while i*i<=m :
   if m%i==0 :
    return False
   else :
    i=i+1
 return True
n=int(input())
p=1
if n!=2 and n%2==0 :
 p=2
elif zhishu(n)==False :
 if zhishu(n-2) :
   p=2
 else :
   p=3
print(p)
  
