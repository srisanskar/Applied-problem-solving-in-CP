def solve():
    t = int(input())
    
    for _ in range(t):
        n, q = map(int, input().split())
        arr = list(map(int, input().split()))
        
        # Compute prefix sums for efficient range sum calculation
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + arr[i]
        
        total_sum = prefix_sum[n]
        
        for _ in range(q):
            l, r, k = map(int, input().split())
            
            # Calculate the sum after the replacement
            # 1. Remove the original sum in range [l, r]
            # 2. Add k * (r - l + 1) for the new values
            original_range_sum = prefix_sum[r] - prefix_sum[l - 1]
            new_range_sum = k * (r - l + 1)
            
            new_total_sum = total_sum - original_range_sum + new_range_sum
            
            if new_total_sum % 2 == 1:
                print("YES")
            else:
                print("NO")

if __name__ == "__main__":
    solve() 