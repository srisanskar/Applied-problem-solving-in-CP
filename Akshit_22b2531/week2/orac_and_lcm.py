from math import gcd

def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    
    if n == 1:
        print(arr[0])
        return
    
    # Calculate pairwise LCMs first
    lcm_val = (arr[0] * arr[1]) // gcd(arr[0], arr[1])
    
    # For each subsequent pair, calculate their LCM and then the GCD with previous result
    for i in range(2, n):
        pair_lcm = (arr[0] * arr[i]) // gcd(arr[0], arr[i])
        lcm_val = gcd(lcm_val, pair_lcm)
    
    # Now check all other pairs
    for i in range(1, n-1):
        for j in range(i+1, n):
            pair_lcm = (arr[i] * arr[j]) // gcd(arr[i], arr[j])
            lcm_val = gcd(lcm_val, pair_lcm)
    
    print(lcm_val)

if __name__ == "__main__":
    solve() 