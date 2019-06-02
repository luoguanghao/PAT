N=int(input())
school=[0]*100001
for i in range(N):
    line=input().split()
    s=int(line[0]); grade=int(line[1])
    school[s]+=grade



maxgrade=0
for i in range(N):
    if school[i]>maxgrade:
        maxgrade=school[i]
        index=i

print(index,maxgrade)