#include <stdio.h>
#include <stdlib.h>

int main(){
	int nexti[9],nextj[9];
	int ktmove1[8]={-2, -2, -1, -1, 1, 1, 2, 2};
	int ktmove2[8]={-1, 1, -2, 2, -2, 2, -1, 1};
	
	for(int size=1;size<=8;size++){
	    int i=0,j=0,k,m,n,p=1,q,npos,min,a,b;
	    int board[8][8]={0};
	    
	    printf("%d:\n",size);
	    do{
	    	npos=0;//��l��npos
	    	board[i][j]=p;
	    	for(k=0;k<8;k++){
	    		if((i+ktmove1[k]>=0) && (i+ktmove1[k]<size) && (j+ktmove2[k]>=0) && (j+ktmove2[k]<size) && (board[i+ktmove1[k]][j+ktmove2[k]]==0)){
	    			nexti[npos]=i+ktmove1[k];
	    			nextj[npos]=j+ktmove2[k];
	    			npos++;
	    		}
	    	}
	    	if(p!=size*size && npos==0){
	    		printf("no solution\n");
	    		goto end;
	    	}
	    	else if(npos==1){
	    		i=nexti[0];
	    		j=nextj[0];//min=0
	    	}
	    	else{
	    	    int exits[9]={};//��l��exits
	    		for(n=0;n<npos;n++){
	    			for(m=0;m<8;m++){
	    				if((nexti[n]+ktmove1[m]>=0) && (nexti[n]+ktmove1[m]<size) && (nextj[n]+ktmove2[m]>=0) && (nextj[n]+ktmove2[m]<size) && (board[nexti[n]+ktmove1[m]][nextj[n]+ktmove2[m]]==0)){
	    					exits[n]++;
	    			    }
	    			}
	    		}
	    		min=0;
	    		for(n=0;n<npos;n++){
	    			if(exits[n]<exits[min])
	    				min=n;
	    		}
	    		i=nexti[min];
	    		j=nextj[min];
	    	}
	    	p++;
	    }while(p<=size*size);
    	for(i=0;i<size;i++){
    	    for(j=0;j<size;j++){
    	        printf("%2d ",board[i][j]);
    	    }
    	    printf("\n");
    	}
    	end:
    	    printf("\n");
    	    continue;
	}
}