def solve():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    
    for _ in range(q):
        a, b = map(int, input().split())
        # Convert to 0-indexed
        a -= 1
        b -= 1
        distinct_values = len(set(arr[a:b+1]))
        print(distinct_values)

if __name__ == "__main__":
    solve() 