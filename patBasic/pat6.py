num=int(input())
output=['','','']
dic=['B','S','1']
tmp=0
divi=100

i=0
while divi>1:
    tmp=int(num/divi)
    output[i]=dic[i]*tmp
    #print(tmp)

    num=num%divi
    divi=divi/10
    i+=1
gewei=''
for i in range(1,int(num)+1):
    gewei=gewei+str(i)
#print(gewei)
output[2]=gewei
#print(output)
printn=''
for i in output:
    printn+=i

print(printn)