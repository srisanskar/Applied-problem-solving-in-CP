a,b=map(int,input().split())

print("YES")

for i in range(a,b+1):
    print(i,end=" ")
    if i%2==0:
        print()