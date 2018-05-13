# -*- coding: utf-8 -*-
n=int(input())
while n>0 :
  n=n-1
  t=int(input())
  f=dict()
  for i in range(26):
    f[chr(ord('A')+i)]=0.0;
  # print(f) result unorder
  while t>0 :
    t=t-1
    p=raw_input()
    if p[2] == '1':
      f[p[0]]+=1
    if p[2] == '-1':
      f[p[1]]+=1
    if p[2] == '0':
      f[p[1]]+=0.5
      f[p[0]]+=0.5
  v=-1
  s=str()
  for (i,p) in f.items():
     if p>v :
      v=p
      s=i 
     if p==v and i<s :
      s=i
  print(s)

#dict in python is unorder ,not key lexicographical order and not insert order!!!
