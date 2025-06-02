n,t=map(int,input().split())

lst=list(map(int,input().split()))

low,high=1,2

def can_make(n,t,lst):
    sum=0
    for x in lst:
        sum+=n//x
    
    if sum>=t:
        return True
    
    return False

while(not can_make(high,t,lst)):
    high*=2

while low<high:
    mid=(low+high)//2
    if(can_make(mid,t,lst)):
        high=mid
    else:
        low=mid+1
    
print(low)


