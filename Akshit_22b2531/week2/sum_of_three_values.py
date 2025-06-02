def solve():
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    
    # Store original indices
    indexed_arr = [(arr[i], i+1) for i in range(n)]
    
    # Sort by value
    indexed_arr.sort()
    
    # For each element, try to find two other elements that sum to x - element
    for i in range(n):
        target = x - indexed_arr[i][0]
        
        # Use two pointers to find the pair
        left = 0
        right = n - 1
        
        while left < right:
            if left == i:
                left += 1
                continue
            if right == i:
                right -= 1
                continue
                
            current_sum = indexed_arr[left][0] + indexed_arr[right][0]
            
            if current_sum == target:
                # Found a solution
                return f"{indexed_arr[i][1]} {indexed_arr[left][1]} {indexed_arr[right][1]}"
            elif current_sum < target:
                left += 1
            else:
                right -= 1
    
    return "IMPOSSIBLE"

if __name__ == "__main__":
    print(solve()) 