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
void delet(treePointer ptr){
	treePointer ptr1,ptr2;
	ptr1=malloc(sizeof(*ptr1));
	ptr2=malloc(sizeof(*ptr2));
	if(!(ptr->leftChild) && !(ptr->rightChild)){
		ptr->data=NULL;
	}
	else if(!(ptr->leftChild)){
		ptr->data=ptr->rightChild->data;
		ptr->leftChild=ptr->rightChild->leftChild;
		ptr->rightChild=ptr->rightChild->rightChild;
	}
	else if(!(ptr->rightChild)){
		ptr->data=ptr->leftChild->data;
		ptr->leftChild=ptr->leftChild->leftChild;
		ptr->rightChild=ptr->leftChild->rightChild;	
	}
	else{
    	ptr1=ptr; 
	    ptr2=ptr->leftChild;
	    while(ptr2->rightChild){ 
	    	ptr1=ptr2; 
			ptr2=ptr2->rightChild;
    	}
    	ptr->data=ptr2->data;
    	if(ptr1!=ptr)	
      		ptr1->rightChild=ptr2->leftChild;
    	else 
      		ptr1->leftChild=ptr2->leftChild;
  	}
}

int main() {
    int i,num=0;
    //int *input=malloc(num*sizeof(int));
    int input[20];
    do{//input data
        num++;
        scanf("%d,",&input[num-1]);
    }while(input[num-1]!=-1);
    treePointer root,node;
    root=malloc(sizeof(*root));
    root->data=input[0];
    root->leftChild=NULL;
    root->rightChild=NULL;
    //create binary search tree
    printf("Create Binary search tree\n");
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
    char c1;
    c1=getchar();//讀取空白
    for(;;){
    	char ans,c2;
    	int element;
    	bool check=false;//判斷element是否在tree裡面
    	treePointer tp=malloc(sizeof(*tp));
        printf("Delete element?(Y/N) :");
        scanf("%c",&ans);
        if(ans=='Y'){
            printf("Choice element:");
            scanf("%d",&element);
            c2=getchar();//讀取空白
            tp=search(root,element,NULL);
            if(element==tp->data){
				check=true;
				delet(tp);
			}
        }
        else if(ans=='N')
            break;

        if(!check)
            printf("%d is not in the tree\n",element);
        else{
            printf("Binary search tree\n");
            num-=1;
        }
    }
}
