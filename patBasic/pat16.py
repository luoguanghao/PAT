line=input().split()
A=line[0]; Da=line[1]; B=line[2]; Db=line[3]

counta=0; countb=0
for i in A:
    if i==Da:
        counta+=1

for i in B:
    if i==Db:
        countb+=1

#print(counta,countb)
Pa=Pb=0
n=1
for i in range(counta):
    Pa += int(Da)*n
    n *= 10
n=1
for i in range(countb):
    Pb += int(Db)*n
    n *= 10

#print(Pa,Pb)

print(Pb+Pa)