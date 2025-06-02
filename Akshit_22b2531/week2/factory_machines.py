def solve():
    n, t = map(int, input().split())
    machines = list(map(int, input().split()))
    
    # Binary search for the minimum time
    left = 0
    right = 10**18  # Upper bound for the answer
    
    while left < right:
        mid = (left + right) // 2
        products = sum(mid // machine for machine in machines)
        
        if products >= t:
            right = mid
        else:
            left = mid + 1
    
    print(left)

if __name__ == "__main__":
    solve() 