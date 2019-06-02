Store=[]; Price=[]; avgP=[]; Visited=[]

line=input().split()
N=int(line[0]); D=int(line[1])

line=input().split()
for i in range(N):
    Store.append(int(line[i]))

line=input().split()
for i in range(N):
    Price.append(int(line[i]))
    
for i in range(N):
    avgP.append(Price[i]/Store[i])

for i in range(N):
    Visited.append(0)

W=0; count=0
while D!=0 and count!=N:
    maxP=0; index=0; count+=1
    
    for i in range(N):
        if(avgP[i]>maxP and Visited[i]==0):
            maxP=avgP[i]
            index=i
    #print(index)
    Visited[index]=1

    if(D<=Store[index]):
        W += D*avgP[index]
        D=0
        
    else:
        D -= Store[index]
        W += Store[index] * avgP[index]

print("%.2f"%W)
