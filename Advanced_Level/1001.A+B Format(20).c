#include<stdio.h>

int main(void) 
{
	int str[8];
	int a, b, sum;
	int flag;

	flag = 1;
	
	scanf("%d %d", &a, &b);
	sum = a + b;
	if (sum < 0){
		flag = 0;
		sum = -sum;
	}
	int i = 0;
	while (sum != 0) {
		str[i++] = sum % 10;
		sum /= 10;
	}
	if (flag == 0)
		printf("-");
	int j;
	for (j = i - 1; j >= 0; j-- ) {
		printf("%d", str[j]);
		if (j % 3 == 0 && j != 0)
			printf(",");
	}
	printf("\n");
	return 0;
}

	

