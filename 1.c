#include <stdio.h>
#include <stdlib.h>
#define Inf 99999999
#define MAXV 100

int main(){
    int e[MAXV][MAXV];
    int Vertex,Edge,v1,v2,weight;
    int i,j,k;

    scanf("%d %d",&Vertex,&Edge);
    for(i=1;i<=Vertex;i++){
        for(j=1;j<=Vertex;j++){
            if(i==j) e[i][j]=0;
            else e[i][j]=Inf;
        }
    }

    for(i=1;i<=Edge;i++){
        scanf("%d %d %d",&v1,&v2,&weight);
        e[v1][v2]=weight;
    }


	for(i=1;i<=Vertex;i++){
        for(j=1;j<=Vertex;j++){
			if(e[i][j]==Inf) printf("      null");
            else printf("%10d",e[i][j]);
        }
        printf("\n");
    }
	


    //floyd
    for(k=1;k<=Vertex;k++){

		printf("   ****** %d ******\n",k);

        for(i=1;i<=Vertex;i++){
            for(j=1;j<=Vertex;j++){
                if(e[i][j] > e[i][k]+e[k][j])
                    e[i][j] = e[i][k]+e[k][j];
            }
        }
		
		for(i=1;i<=Vertex;i++){
			for(j=1;j<=Vertex;j++){
				if(e[i][j]==Inf) printf("      null");
				else printf("%10d",e[i][j]);
			}
			printf("\n");
		}
		
		
    }

/*
    for(i=1;i<=Vertex;i++){
        for(j=1;j<=Vertex;j++){
            printf("%10d",e[i][j]);
        }
        printf("\n");
    }

*/

    return 0;
}
