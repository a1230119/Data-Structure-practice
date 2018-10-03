#include<stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 9

typedef struct node *listPointer;
struct node{
    int data;
    listPointer link;
};
void insert(listPointer x,int k){
	listPointer temp;
	temp=malloc(sizeof(*temp));
	temp->data=k;
	temp->link=x->link;
	x->link=temp;
}

int main() {
    int cost[MAX_VERTICES][MAX_VERTICES]={{0,5,4,2,99,99,99,99,99},{99,0,99,99,3,99,99,99,99},{99,1,0,99,2,8,99,99,99},{99,99,1,0,99,7,99,99,99},{99,99,99,99,0,99,7,10,15},{99,99,99,99,99,0,99,3,99},{99,99,99,99,99,99,0,99,6},{99,99,99,99,99,99,99,0,5},{99,99,99,99,99,99,99,99,0}};
    int distance[MAX_VERTICES][MAX_VERTICES]={0};
    int i,j,k,input1,input2;
    int path[MAX_VERTICES][MAX_VERTICES];
    scanf("%d %d",&input1,&input2);
    listPointer first=malloc(sizeof(*first));
    listPointer last=malloc(sizeof(*last));
    last->data=input2;
    last->link=NULL;
    first->data=input1;
    first->link=last;
    for(i=0;i<MAX_VERTICES;i++)
        for(j=0;j<MAX_VERTICES;j++)
            distance[i][j]=cost[i][j];
    for(k=0;k<MAX_VERTICES;k++){
        for(i=0;i<MAX_VERTICES;i++){
            for(j=0;j<MAX_VERTICES;j++){
                if(distance[i][k]+distance[k][j]<distance[i][j]){
                    distance[i][j]=distance[i][k]+distance[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    listPointer middle=malloc(sizeof(*middle));
    if(distance[input1][input2]!=cost[input1][input2]){
    	insert(first,path[input1][input2]);
    	middle=first->link;
		while(distance[input1][middle->data]!=cost[input1][middle->data]){
    		insert(first,path[input1][middle->data]);
    		middle=first->link;
    	}
    	while(distance[middle->data][middle->link->data]!=cost[middle->data][middle->link->data]){
    		insert(middle,path[middle->data][middle->link->data]);
    		middle=middle->link;
    	}
    	
    }
    
    if(distance[input1][input2]>=99)
        printf("No solution\n");
    else{
        printf("Distance :%d\n",distance[input1][input2]);
        printf("The route for the shortest path : %d",input1);
        while((first->link)!=NULL){
        	printf("→%d",first->link->data);
        	first=first->link;
        }
        printf("\n");
    }
}