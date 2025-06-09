def solve():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        parents = list(map(int, input().split()))
        
        # Build the tree as an adjacency list (children for each node)
        tree = [[] for _ in range(n+1)]
        for i in range(n):
            # 1-indexed
            node = i + 1
            parent = parents[i]
            if node != parent:  # Skip self-loops (root)
                tree[parent].append(node)
        
        # Find the root
        root = 0
        for i in range(n):
            if parents[i] == i + 1:
                root = i + 1
                break
        
        # Create paths
        paths = []
        visited = [False] * (n+1)
        
        def dfs(node):
            visited[node] = True
            
            # Try to extend the path as far down as possible
            current_path = [node]
            
            # If there's exactly one unvisited child, extend the path
            while True:
                unvisited_children = [child for child in tree[node] if not visited[child]]
                
                if len(unvisited_children) != 1:
                    break
                
                node = unvisited_children[0]
                visited[node] = True
                current_path.append(node)
            
            # Add the current path
            paths.append(current_path)
            
            # Process remaining unvisited children with new paths
            for child in tree[node]:
                if not visited[child]:
                    dfs(child)
        
        # Start DFS from the root
        dfs(root)
        
        # Output
        print(len(paths))
        for path in paths:
            print(len(path))
            print(*path)

if __name__ == "__main__":
    solve() 