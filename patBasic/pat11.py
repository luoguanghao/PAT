N=int(input())
for i in range(N):
    line=input().split(" ")
    if(int(line[0])+int(line[1])>int(line[2])):
        print("Case #%d: true"%(i+1))
    else:
        print("Case #%d: false"%(i+1))