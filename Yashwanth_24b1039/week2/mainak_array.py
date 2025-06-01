from math import gcd
from math import lcm

n=int(input())

lst=list(map(int,input().split()))

gcd_prefix=[0]*n
gcd_suffix=[0]*n
gcd_prefix[0]=lst[0]
gcd_suffix[n-1]=lst[n-1]

for i in range(1,n):
    gcd_prefix[i]=gcd(gcd_prefix[i-1],lst[i])

for i in range(n-2,-1,-1):
    gcd_suffix[i]=gcd(gcd_suffix[i+1],lst[i])

gcd_remaining=[0]*n
gcd_remaining[0]=gcd_suffix[1]
result=gcd_remaining[0]
for i in range(1,n-1):
    gcd_remaining[i]=gcd(gcd_prefix[i-1],gcd_suffix[i+1])
    result=lcm(result,gcd_remaining[i])

result=lcm(result,gcd_prefix[n-2])

print(result)