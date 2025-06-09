s=int(input())

output=[]

while(s>0):

    n,q=map(int,input().split())
    lst=list(map(int,input().split()))
    sum_lst=[0]*n
    sum_lst[0]=lst[0]
    for i in range(1,n):
        sum_lst[i]=sum_lst[i-1]+lst[i]
    
    for _ in range(q):
        l,r,k=map(int,input().split())
        sum=sum_lst[r-1]-(sum_lst[l-2] if l>1 else 0)
        if(sum_lst[n-1]-sum+(l-r+1)*k)%2==1:
            output.append("YES")
        else:
            output.append("NO")
    s-=1

print("\n".join(output))