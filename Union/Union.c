#include<stdio.h>
#include<stdlib.h>

int main() {
    int m,n;
    scanf("%d",&n);
    int *parent=malloc(n*sizeof(int));
    for(m=0;m<n;m++){
        *(parent+m)=-1;
    }
    void heightUnion(int i,int j){
       if(parent[i]>parent[j]){
           parent[i]=j;
       }
       else{
       		if(parent[i]==parent[j])
       			parent[i]-=1;
    		parent[j]=i;   
       }
	}
	for(m=1;m<n;m++){
		heightUnion(0,m);
	}
	printf("Node parent\n");
	for(m=0;m<n;m++){
		if(parent[m]<0)
			printf("%-4d root\n",m);
		else
			printf("%-4d %-5d\n",m,parent[m]);
	}
}
