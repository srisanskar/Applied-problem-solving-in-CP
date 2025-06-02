from math import gcd

def solve():
    l, r = map(int, input().split())
    
    # Check if we can form (r-l+1)/2 pairs
    n = r - l + 1
    if n % 2 != 0:
        print("NO")
        return
    
    print("YES")
    
    # Simple solution: pair consecutive numbers
    # Any two consecutive integers are always relatively prime (their GCD is 1)
    for i in range(l, r, 2):
        print(i, i+1)

if __name__ == "__main__":
    solve() 