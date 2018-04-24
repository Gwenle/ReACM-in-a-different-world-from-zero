def zhishu(m):
 i=2
 while i*i<=m :
   if m%i==0 :
    return False
   else :
    i=i+1
 return True
n=int(input())
p=0
while n!=0 :
 k=n
 while zhishu(k)==False :
  k=k-1
 n=n-k
 p=p+1
print(p)
  
