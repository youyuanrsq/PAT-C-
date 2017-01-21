#include<stdio.h>
#include<stdbool.h>

bool isprime(int a);

bool isprime(int a)
{
	int i;

	for (i = 2; i * i <= a; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int main(void)
{
	int N;
	int i;
	int count = 0;
	
	scanf("%d", &N);
	for (i = 5; i <= N; i++) {
		if (isprime(i-2) && isprime(i))
			count++;
	}

	printf("%d", count);
	return 0;
}
