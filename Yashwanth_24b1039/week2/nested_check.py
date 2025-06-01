n=int(input())
ranges=[tuple(map(int,input().split()))+(i,) for i in range(n)]

ranges.sort(key=lambda x: (x[0], -x[1]))

contains=[0]*n
contained=[0]*n

max_end=-10**15
for x,y,i in ranges:
    if y<=max_end:
        contains[i]=1
    else:
        max_end=y

min_end=10**15
for x,y,i in reversed(ranges):
    if y>=min_end:
        contained[i]=1
    else:
        min_end=y

print(*contained)
print(*contains)


