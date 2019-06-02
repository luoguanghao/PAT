import math

def NextPrime(n):
    if n==1:
        return 2
    elif n==2:
        return 3

    n+=1
    if(n%2==0):
        n+=1
    while True:
        
        i=int(math.sqrt(n))
        while i>2:
            if(n%i==0):
                break
            i-=1
        if(i==2):
            break
        n+=2
    
    return n




num=int(input())

count=0
p=1
r=NextPrime(p)
while r<=num:
    if(r-p==2):
        #print('*',p,r)
        count+=1
    
    p=r
    r=NextPrime(p)

print(count)