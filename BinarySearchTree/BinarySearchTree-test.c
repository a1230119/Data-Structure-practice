#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct node *treePointer;
struct node{
    int data;
    treePointer leftChild,rightChild;
};
treePointer search(treePointer root,int k,treePointer parent){
    if(!root)
        return parent;
    else if(k==root->data)
        return root;
    else if(k<root->data)
        return search(root->leftChild,k,root);
    else
        return search(root->rightChild,k,root);
}
void insert(treePointer node,treePointer root){
    treePointer temp=search(root,node->data,NULL);
    if(node->data < temp->data)
        temp->leftChild=node;
    else if(node->data > temp->data)
        temp->rightChild=node;
    else
        printf("error");
}
void printp(treePointer ptr){
    if(!ptr)
        printf("*  ");
    else
        printf("%-3d",ptr->data);
}

int main() {
    printf("Create Binary search tree\n");
    int i,num=0;
    //int *input=malloc(num*sizeof(int));
    int input[20];
    do{
        num++;
        scanf("%d,",&input[num-1]);
    }while(input[num-1]!=-1);
    treePointer root,node;
    root=malloc(sizeof(*root));
    root->data=input[0];
    root->leftChild=NULL;
    root->rightChild=NULL;
    //create binary search tree
    for(i=1;i<num-1;i++){
        node=malloc(sizeof(*node));
        node->data=input[i];
        node->leftChild=NULL;
        node->rightChild=NULL;
        //printf("%d\n",node->data);
        insert(node,root);
    }
    
    int q=0,p=1,r=0,t=1;//q:計算queue的大小/p:依序印出queue的內容/r:計算queue上限/t:計算何時換行
    treePointer *queue=malloc((q+1)*sizeof(*root));
    treePointer temp;
    temp=malloc(sizeof(*temp));
    temp=root;
    queue[++q]=temp;
    r++;
    for(;;){//print成binary search tree的樣子
        printp(queue[p]);
        if(p+1==pow(2,t)){
            printf("\n");
            t++;
        }
        p++;
        if(temp){
            queue[++q]=temp->leftChild;
            if(queue[q])    r++;
            queue[++q]=temp->rightChild;
            if(queue[q])    r++;
        }
        else{
            queue[++q]=NULL;
            queue[++q]=NULL;
        }
        if(r==num-1){
            for(i=p;i<=q;i++){
                printp(queue[i]);
                if(i+1==pow(2,t)){
                    printf("\n");
                    t++;
                }
                if(i==q)
                    printf("\n");
            }
            break;
        }
        temp=queue[p];
    }
    
    
    for(;;){
    	char ans,c;
    	int element;
    	bool check=false;//判斷element是否在tree裡面
        printf("Delete element?(Y/N) :");
        scanf("%c",&ans);
        if(ans=='Y'){
            printf("Choice element:");
            scanf("%d",&element);
            c=getchar();//讀取空白
            for(i=0;i<num-1;i++){
                if(element==input[i]){
                    check=true;
                    break;
                }
            }
        }
        else if(ans=='N')
            break;

        if(!check)
            printf("%d is not in the tree\n",element);
        else{
            printf("haha\n");
        }
    }
}