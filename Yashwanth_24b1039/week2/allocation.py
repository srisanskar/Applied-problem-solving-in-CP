n=int(input())

checkin=[0]*n
checkout=[0]*n

for i in range(n):
    checkin[i],checkout[i]=map(int,input().split())

perm=sorted(range(n) ,key=lambda i:checkin[i])

checkin.sort()
temp=checkout.copy()
for i in range(n):
    checkout[i]=temp[perm[i]]


room_no=[]
room_vacancy=[]
for i in range(n):
    allocated=False
    for j in range(len(room_vacancy)):
        if(room_vacancy[j]<checkin[i]):
            room_vacancy[j]=checkout[i]
            room_no.append(j+1)
            allocated=True
            break
    if not allocated:
        room_vacancy.append(checkout[i])
        room_no.append(len(room_vacancy))

print(max(room_no))
temp=room_no.copy()
for i in range(n):
    room_no[perm[i]]=temp[i]
print(*room_no)
