# str list的转换 || 排序 #

line=list(input())
count=[0,0,0,0,0,0,0,0,0,0]
for i in line:
    count[int(i)]+=1

#print(count)

for i in range(10):
    if(count[i]!=0):
        print("%d:%d"%(i,count[i]))
####### 表排序 ##########
SortLink=[]
for i in range(10):
    SortLink.append(i)

tmp=0
i=1
while(i<10):
    tmp=SortLink[i]
    j=i-1
    while j>=0:
        if count[tmp]<count[SortLink[j]]:
            SortLink[j+1]=SortLink[j]
        else:
            break
        j-=1
    SortLink[j+1]=tmp
    i+=1

for i in range(10):
    print(SortLink[i],count[SortLink[i]])
    