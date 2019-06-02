#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXP 1000
#define MAXL 100
#define MAXC 81

struct PageType{
    int Next;
    char cont[MAXL][MAXC];
}Page[MAXP]; //直接在这里创建了结构数组Page？

void Read(int Pn, int Ln){
    int i,j;
    getchar(); //上一函数scanf()不读入'\n'故缓冲区的'n'会被fget读入，加一个getchar就好
    for(i=0;i<Pn;i++){ //Page
        for(j=0;j<Ln;j++){ //Line
            fgets(Page[i].cont[j],MAXC,stdin); //用fgets()代替gets()
            if(Page[i].cont[j][strlen(Page[i].cont[j])-1]=='\n')
                Page[i].cont[j][strlen(Page[i].cont[j])-1]='\0';
            Page[i].Next=-2;  //表示没读过
        }
        
    }
}

int SortPage(int Pn, int Ln){
    int trail,head,i;

    head = trail = 0;
    Page[0].Next = -1;

    if(Pn == 1) return 0;

    i=1;
    while(i!=trail){
        if(Page[i].Next==-2 && 
            !strcmp(Page[i].cont[0],Page[trail].cont[Ln-1])){
            Page[trail].Next = i;
            trail = i;
            Page[trail].Next = -1;
        }
        i = (i+1)%Pn;
    }

    i=1;
    while(i!=head){
        if(Page[i].Next==-2 &&
           !strcmp(Page[i].cont[Ln-1],Page[head].cont[0])){
            Page[i].Next = head;
            head = i;
           }
           i=(i+1)%Pn;
    }

    return head;
}

void OutPut(int head, int Ln){ //
    int i,j;
    
    for(i=0; i<Ln; i++){
        printf("outPut\n%s\n",Page[head].cont[i]);
    }
    for(i=Page[head].Next; i!=-1; i=Page[i].Next){
        for(j=1; j<Ln; j++){
            printf("%s\n",Page[i].cont[j]);
        }
    }
}

int main(){
    int Pn,Ln,head;

    scanf("%d %d",&Pn,&Ln);
    Read(Pn,Ln);
    head=SortPage(Pn,Ln);
    OutPut(head,Ln);

    return 0;
}