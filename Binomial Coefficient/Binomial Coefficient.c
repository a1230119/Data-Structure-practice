#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binomial_coefficient(int n, int k){
	if(k == n || k == 0)
		return 1;
	else
		return binomial_coefficient(n-1, k) + binomial_coefficient(n-1, k-1);
}
int main(){
	int n, k;
	printf("input two positive integers n, k to compute a binomial coefficient (n k)\n");
	scanf("%d %d", &n, &k);
	if(k > n)
		printf("format error\ninput(n k)\n");
	else
		printf("%d\n", binomial_coefficient(n, k));
}
