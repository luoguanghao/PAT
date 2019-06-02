
def Move(In):
    enditem=In[len(In)-1]
    for i in range(len(In)-2,-1,-1):
        #print(In[i])
        In[i+1]=In[i]
    In[i]=enditem



line=input()
num = line.split(" ")[0]
times = line.split(" ")[1]
In=[]
line2=input()
for i in range(int(num)):
    In.append(line2.split(" ")[i])
for i in range(int(times)):
    Move(In)

#print(In)
#print(In[len(In)-1])

for i in range(len(In)-1):
    print(In[i],end=" ")
print(In[len(In)-1])

