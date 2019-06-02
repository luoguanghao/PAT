import math

def NextPrime(n):
    if(n==1):
        return 2
    elif(n==2):
        return 3
    elif(n==0):
        return 1

    n+=1
    if(n%2==0):
        n+=1
    while True:
        i=int(math.sqrt(n))
        while i>2:
            if n%i==0:
                break
            i-=1
        if i==2:
            break
        n+=2
        
    return n

#print(NextPrime(int(input())))

line=input().split(" ")
a=int(line[0]) ; b=int(line[1])
i=1
lay=1
prime=0
while i<=b+1:
    prime=NextPrime(prime)
    if a<i and i<b+1:    
        if lay%10==0:
            print(prime)
        else:
            print(prime,end=' ')
        lay+=1
    if i==b+1:
        print(prime,end='')
            
    i+=1 ; 