#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1001

int main(){
	typedef struct{
		short int vert;
		short int horiz;
	}offsets;
	offsets move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
	typedef struct{
		short int row;
		short int col;
		short int dir;
	}element;
	int i,j,n,m,N,M,s=2,t;
	int source_row,source_col,destination_row,destination_col;//�_�I���I���y�� 
	char maze[MAX+2][MAX+2];
	char ch;
	scanf("%d %d",&N,&M);//N*M matrix
	ch=getchar();//����'\n' 
	for(i=0;i<N+2;i++){
		for(j=0;j<M+2;j++){
			maze[i][j]='1';
		}
	}
	for(n=1;n<=N;n++){
		for(m=1;m<=M+1;m++){
			ch=getchar();
			if(ch=='\n'){
				continue;
			}//�׶}'\n' 
			else{
				maze[n][m]=ch;	
				if(ch=='s'){
					source_row=n;
					source_col=m;
				}
				else if(ch=='d'){
					destination_row=n;
					destination_col=m;
				}
				else if(ch=='0'){
					s++;//s��stack���W�� 
				}
			}
		}
	}

	int row,col,dir,nextRow,nextCol,top,found=false;//false=0
	int mark[N+2][M+2];//�O�����L����
	for(i=0;i<N+2;i++){
		for(j=0;j<M+2;j++){
			mark[i][j]=0;
		}
	}
	element position;
	element stack[s];
	mark[source_row][source_col]=1;
	top=0;
	stack[0].row=source_row;
	stack[0].col=source_col;
	stack[0].dir=1;

	while(top>-1 && !found){//�����|�ӥB�S���X�f
		position=stack[top--];//�N���|�̤W�����������X��
		row=position.row;
    	col=position.col;
    	dir=position.dir;
    	while(dir<8 && !found){
    		nextRow=row+move[dir].vert;
			nextCol=col+move[dir].horiz;
			if(nextRow==destination_row && nextCol==destination_col){//���X�f 
			    position.row=row;//�{�brow��m
				position.col=col;
				position.dir=++dir;//�U��������V
				stack[++top]=position;
				found=true;
			}
			else if((maze[nextRow][nextCol]-'0')!=1 && mark[nextRow][nextCol]!=1){//���i�H���B�O�S���L����
				mark[nextRow][nextCol]=1;
				position.row=row;//�{�brow��m
				position.col=col;
				position.dir=++dir;//�U��������V
				stack[++top]=position;
				row=nextRow;
				col=nextCol;
				dir=0;
			}
			else
				++dir;
		}
	}
	if(found){
		for(t=1;t<=top;t++){
		    maze[stack[t].row][stack[t].col]='*';
		}
		for(i=1;i<=N;i++){
		    for(j=1;j<=M;j++){
			    printf("%c",maze[i][j]);
		    }
		    printf("\n");
    		}
		printf("%d steps\n",top+2);
	}
	else
		printf("No route");

}
