In=input().split(" ")
Out=[]
#print(In)
for i in range(0,len(In),2):
    #print(In[i])
    x=int(In[i])
    exon=int(In[i+1])
    if exon==0:
        if len(In)==2:
            Out.append(0)
            Out.append(0)
        else:
            continue
    else:
        Out.append(x * exon)
        Out.append(exon - 1)
for i in range(len(Out)-1):
    print(Out[i],end=" ")
print(Out[i+1])
