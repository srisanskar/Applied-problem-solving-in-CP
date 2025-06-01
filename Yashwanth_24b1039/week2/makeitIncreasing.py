s=int(input())

def dfs_itr(root,adj):
    visited=[False]*(n+1)
    stack=[root]
    visited[root]=True
    path=[[]]
    while stack:
        node=stack.pop()
        path[-1].append(node)
        if(len(adj[node])==1 and node!=root):
            path.append([])
        for x in reversed(adj[node]):
            if not visited[x]:
                visited[x]=True
                stack.append(x)
        
    return path


    

while(s>0):

    n=int(input())
    parent=list(map(int,input().split()))

    adj=[[] for _ in range(n+1)]
    root=0
    for i in range(n):
        if parent[i]!=i+1:
            adj[i+1].append(parent[i])
            adj[parent[i]].append(i+1)
        else:
            root=i+1

    output=dfs_itr(root,adj)
    print(max(1,len(output)-1))
    for lst in output:
        if len(lst)!=0:
            print(len(lst))
        print(*lst)
    s-=1