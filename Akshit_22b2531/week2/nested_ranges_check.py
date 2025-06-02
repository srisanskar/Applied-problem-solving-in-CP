def solve():
    n = int(input())
    ranges = []
    
    for i in range(n):
        x, y = map(int, input().split())
        ranges.append((x, y, i))  # Store original index
    
    contains = [0] * n
    contained = [0] * n
    
    # Check each pair of ranges
    for i in range(n):
        for j in range(n):
            if i != j:
                # Range i contains range j if start_i <= start_j and end_j <= end_i
                if ranges[i][0] <= ranges[j][0] and ranges[j][1] <= ranges[i][1]:
                    contains[ranges[i][2]] = 1
                    contained[ranges[j][2]] = 1
    
    print(*contains)
    print(*contained)

if __name__ == "__main__":
    solve() 