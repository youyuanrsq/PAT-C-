#include<stdio.h>

void print_c(int n, char c);
void print_d(int n);

int main()
{
	int digit[3];
	int n;
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < 3; i++)
		digit[i] = 0;
	j = 0;
	while (n > 0) {
		digit[j++] = n % 10;
		n /= 10;
	}

	for (i = j-1; i >= 0; i--) {
		switch (i) {
			case 0:
				print_d(digit[i]);
				break;
			case 1:
				print_c(digit[i], 'S');
				break;
			case 2:
				print_c(digit[i], 'B');
				break;
			case 3:
				print_c(digit[i], 'Q');
				break;
			default:
				break;
		}
	}
	/*
	for (i = digit[2]; i > 0; i--) 
		printf("B");
	for (i = digit[1]; i > 0; i--) 
		printf("S");
	for (i = digit[0], j = 1; i > 0; i--, j++) 
		printf("%d", j);
	*/
	return 0;
}

void print_c(int n, char c)
{
	int i;

	for (i = n; i > 0; i--)
		printf("%c", c);
	return;
}

void print_d(int n)
{
	int i, j;

	for (i = n, j = 1; i > 0; i--, j++)
		printf("%d", j);
	return;
}
