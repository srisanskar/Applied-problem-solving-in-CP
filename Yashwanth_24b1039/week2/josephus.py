from collections import deque
 
n,k=map(int,input().split())
 
dq=deque(range(1,n+1))
 
 
while n>0:
 
    dq.rotate(-(k%n))
    print(dq.popleft(),end=" ")
 
    n-=1
 
print()

