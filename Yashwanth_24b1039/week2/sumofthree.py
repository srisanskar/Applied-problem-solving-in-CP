n,x=map(int,input().split())

lst=list(map(int,input().split()))

idx=sorted(range(1,n+1),key=lambda i:lst[i-1])

lst.sort()

for i in range(n):
    target=x-lst[i]
    l,r=i+1,n-1
    while(l<r):
        sum=lst[l]+lst[r]
        if sum==target:
            print(idx[i],idx[l],idx[r])
            exit()
        elif sum>target:
            r-=1
        elif sum<target:
            l+=1

print("IMPOSSIBLE")

