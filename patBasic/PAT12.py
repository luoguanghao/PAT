A1=A2=A3=A4=A5=0
countA4=0
In=input().split(" ")
A2array=[]
for i in range(1,len(In)):
    if int(In[i])%10==0:
        A1 += int(In[i])
    elif int(In[i])%5==1:
        A2array.append(int(In[i]))
    elif int(In[i])%5==2:
        A3+=1
    elif int(In[i])%5==3:
        A4 += int(In[i])
        countA4 += 1
    elif int(In[i])%5==4 and int(In[i])>A5:
        A5 = int(In[i])

for i in range(0,len(A2array),2):
    A2 += A2array[i]
    if i+1<len(A2array):
        A2 -= A2array[i+1]

if A1==0:
    A1="N"
if A2array==[]:
    A2="N"

if A4==0:
    A4="N"
else:
    A4="{0:.1f}".format(A4/countA4)
if A5==0:
    A5="N"
print(A1,A2,A3,A4,A5)