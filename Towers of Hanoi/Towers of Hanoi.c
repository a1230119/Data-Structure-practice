#include <stdio.h>

void move(int, char, char, char);
long long int i = 0;

int main(){
	int disk_num;
	printf("(disks number 3~64)\n");
	scanf("%d", &disk_num);
		if(disk_num < 3 || disk_num > 64)
			printf("(disks number 3~64)\n");
		else{
			printf("Disk:%d\n", disk_num);
			move(disk_num, 'A', 'B', 'C');
			printf("Total steps:%d\n", i);
		}
	system("pause");
}
void move(int layer, char A, char B, char C){
	if(layer == 1){
		printf("Move disk %d from %c to %c\n", layer, A, B);
		i++;
		return;
	}
	else{
		move(layer-1, A, C, B);
		printf("Move disk %d from %c to %c\n", layer, A, B);
		i++;
		move(layer-1, C, B, A);
		return;
	}
} 
