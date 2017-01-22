#include<stdio.h>

int main(void)
{
	char s[10][10];
	int i, c;
	
	i = c = 0;
	while (c != '\n') {
		scanf("%s", &s[i++][0]);
		c = getchar();			/* 读走换行符 */
	}
	int j;
	for (j = i-1; j >= 0; j--) {
		printf("%s", &s[j][0]);
		if (j > 0)
			printf(" ");
	}

	return 0;
}

