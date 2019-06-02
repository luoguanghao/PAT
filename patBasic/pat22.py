line=input().split(" ")
line=sorted(line)
visited=[]
for i in range(len(line)):
    visited.append(0)
out='a'
count=1
for i in range(len(line)):
    if i != 0:
        line[i].join(out)
        visited[i]=1
        break

while(count!=len(line)):
    for i in range(len(line)):
        if i != 0 :
            line[i].join(out)
            visited[i]=1
            count+=1

print(out)