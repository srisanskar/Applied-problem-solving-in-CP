from sortedcontainers import SortedList

def solve():
    n, k = map(int, input().split())
    
    # Use SortedList for efficient indexing and removal
    circle = SortedList(range(1, n+1))
    
    pos = 0
    result = []
    
    for _ in range(n):
        # Calculate the next position to remove
        pos = (pos + k) % len(circle)
        # Add the removed child to result
        result.append(circle.pop(pos))
    
    print(*result)

if __name__ == "__main__":
    solve() 