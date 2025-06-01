import heapq

def solve():
    n = int(input())
    customers = []
    
    for i in range(n):
        arrival, departure = map(int, input().split())
        # Store customer index for output order
        customers.append((arrival, departure, i))
    
    # Sort by arrival time
    customers.sort()
    
    rooms = []  # Min heap of (departure_time, room_number)
    room_assignments = [0] * n
    next_room = 1
    
    for arrival, departure, idx in customers:
        # Check if any room is free (has departure time <= current arrival)
        if rooms and rooms[0][0] <= arrival:
            # Reuse this room
            _, room_num = heapq.heappop(rooms)
            heapq.heappush(rooms, (departure, room_num))
            room_assignments[idx] = room_num
        else:
            # Need a new room
            heapq.heappush(rooms, (departure, next_room))
            room_assignments[idx] = next_room
            next_room += 1
    
    print(len(rooms))
    print(*room_assignments)

if __name__ == "__main__":
    solve() 