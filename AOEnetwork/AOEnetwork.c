#include<stdio.h>
#include<stdlib.h>

typedef struct node *nodePointer;
struct node{
    int vertex;
    int dur;
    nodePointer link;
};
typedef struct{
    int count;//入分支度
    nodePointer link;
}hdnodes;
void topsort(hdnodes graph[],int n,int earliest[],int order[],int latest[]){//n=vertex number
    int i,j,k,top,mindur;
    nodePointer ptr,temp;
    top=-1;
    for(i=0;i<n;i++){
        if(!graph[i].count){
            graph[i].count=top;
            top=i;
        }
    }
    for(i=0;i<n;i++){
        if(top==-1)
            break;
        else{
            j=top;
            top=graph[top].count;
            order[i]=j;
            for(ptr=graph[j].link;ptr;ptr=ptr->link){
                k=ptr->vertex;
                if(earliest[k]<earliest[j]+ptr->dur)
                    earliest[k]=earliest[j]+ptr->dur;
                graph[k].count--;
                if(!graph[k].count){
                    graph[k].count=top;
                    top=k;
                }
            }
        }
    }
    latest[n-1]=earliest[n-1];
    for(i=n-2;i>=0;i--){
        temp=graph[order[i]].link;
        mindur=latest[temp->vertex]-temp->dur;
        while(temp->link != NULL){
            temp=temp->link;
            if(latest[temp->vertex]-temp->dur<mindur)
                mindur=latest[temp->vertex]-temp->dur;
        }
        latest[order[i]]=mindur;
    }
}

int main() {
    int n,i,activitynumber,startvertex,endvertex,activityrequire,v=0;
    scanf("%d",&n);//total activities number
    hdnodes *event=malloc(n*sizeof(hdnodes));
    int *a=malloc((n+1)*sizeof(int));
    int *b=malloc((n+1)*sizeof(int));
    int *c=malloc((n+1)*sizeof(int));
    for(i=0;i<n;i++){
        event[i].count=0;
        event[i].link=NULL;
    }
    for(i=0;i<n;i++){
        nodePointer ptr=malloc(sizeof(*ptr));
        nodePointer temp=malloc(sizeof(*temp));
        ptr->link=NULL;
        scanf("%d %d %d %d",&activitynumber,&startvertex,&endvertex,&activityrequire);
        a[activitynumber]=startvertex;
        b[activitynumber]=endvertex;
        c[activitynumber]=activityrequire;
        if(v<endvertex)
            v=endvertex;//compute vertex number
        event[endvertex].count++;
        ptr->vertex=endvertex;
        ptr->dur=activityrequire;
        if(event[startvertex].link == NULL)
            event[startvertex].link=ptr;
        else{
            temp=event[startvertex].link;
            while(temp->link != NULL){
                temp=temp->link;
            }
            temp->link=ptr;
        }
    }
    int *ee=malloc((v+1)*sizeof(int));
    int *le=malloc((v+1)*sizeof(int));
    int *order=malloc((v+1)*sizeof(int));//stack order
    int *e=malloc((n+1)*sizeof(int));//early time
    int *t=malloc((n+1)*sizeof(int));//late time
    int *s=malloc((n+1)*sizeof(int));//slack
    char *yn=malloc((n+1)*sizeof(int));//critical activity or not
    for(i=0;i<=v;i++){
        ee[i]=0;
        le[i]=0;
    }
    topsort(event,v+1,ee,order,le);
    for(i=1;i<=n;i++){
    	e[i]=ee[a[i]];
    	t[i]=le[b[i]]-c[i];
    	s[i]=t[i]-e[i];
    	if(s[i]==0)
    		yn[i]='Y';
    	else
    		yn[i]='N';
    }
    printf("a.\n    e   l\n");
    for(i=0;i<=v;i++){
        printf("%-3d %-3d %d\n",i,ee[i],le[i]);
    }
    printf("\nb.\n    e   t   s   c\n");
    for(i=1;i<=n;i++){
    	printf("%-3d %-3d %-3d %-3d %-3c\n",i,e[i],t[i],s[i],yn[i]);
    }
}
