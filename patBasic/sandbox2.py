count=[7,5,8,1,4,2,3,9]
tmp=0

i=1
while(i<8):
    tmp=count[i]
    j=i-1
    while(j>=0):
        if(count[j]>tmp):
            count[j+1]=count[j]
        else:
            break
        j-=1
    count[j+1]=tmp
    i+=1

for i in range(8):
    print(count[i])