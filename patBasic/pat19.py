#格式输出#

def UPSort(n):
    tmp=str(n)
    tmp=sorted(tmp)
    tmp=('').join(tmp)
    return int(tmp)

def DWSort(n):
    tmp=str(n)
    tmp=sorted(tmp,reverse=True)
    tmp=('').join(tmp)
    return int(tmp)

n=int(input())
while(n!=6174 and n!=0):
    a=DWSort(n) ; b=UPSort(n)
    n=a-b
    print("%04d - %04d = %04d"%(a,b,n))
