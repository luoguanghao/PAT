line=input().split()

A=line[0]; B=int(line[1])

if len(A)==1 and int(A)<=B:
    print(int(int(A)/B),int(A)%B)
else:
    remainder=0; index=0; result=[]

    for i in range(len(A)):
        remainder = remainder*10 + int(A[i])
        if(len(result) or remainder>=B):
            result.append(int(remainder/B))
            remainder=remainder%B

    for i in result:
        print(i,end="")
    print(" ",end='')
    print(remainder)