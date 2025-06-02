n,q=map(int,input().split())

lst=list(map(int,input().split()))

distinct_lst=[]

for i in lst:
    if i not in distinct_lst:
        distinct_lst.append(i)

nd=len(distinct_lst)
# print(distinct_lst)
memo=[[0]for _ in range(nd)]


for i in range(1,n+1):
    for j in range(nd):
        memo[j].append(memo[j][i-1]) 
        if distinct_lst[j]==lst[i-1]:
            memo[j][i]+=1

while(q>0):

    a,b=map(int,input().split())
    result=0
    for i in range(nd):
        if (memo[i][b]-memo[i][a-1])>0:
            result+=1 
        if(result==nd):
            break
    
    print(result)
    q-=1

    
