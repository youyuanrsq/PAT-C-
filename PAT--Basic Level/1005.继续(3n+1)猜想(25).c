/*
1005. 继续(3n+1)猜想 (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例：
6
3 5 6 7 8 11
输出样例：
7 6
*/
#include<stdio.h>
#define MAXLENGTH 100

int isin(int x, int d[]);
void sort_d(int d[], int len);

int main(void)
{
	int test_d[MAXLENGTH];
	int result_d[MAXLENGTH];
	int divide_d[MAXLENGTH];
	int i, n, j, len;
	/* 初始化数组 */
	for (i = 0; i < MAXLENGTH; i++) {
		test_d[i] = 0;
		result_d[i] = 0;
		divide_d[i] = 0;
	}
	
	scanf("%d", &n);
	int temp_d[n];
	/* 获取测试数据 */
	for (i = 0; i < n; i++) 
		scanf("%d", &test_d[i]);
	/* 保存数据样本 */
	for (i = 0; i < n; i++)
		temp_d[i] = test_d[i];
	/* 把每个数据按卡拉兹猜想拆分装入数组 */
	for (i = 0, j = 0; i < n; i++) {
		while (test_d[i] != 1) {
			if (test_d[i] % 2 != 0) {
				test_d[i] = 3 *test_d[i] + 1;
			}
			test_d[i] /= 2;
			if (test_d[i] != 1 && isin(test_d[i], divide_d) != 1) /* 装入数组前做去重处理 */
				divide_d[j++] = test_d[i];
		}
	}
		
	for (i = 0, j = 0; i < n; i++) {
		if (isin(temp_d[i], divide_d) == 1)  	/* 判断测试数据是否在拆分数组内,如果在pass */
			;
		else
			result_d[j++] = temp_d[i]; 			/* 在不保存在result_d数组内*/
	}
	sort_d(result_d, j);						/* 对resule_d数组进行排序 */
	for (i = 0; i < j; i++) {
		printf("%d",result_d[i]);
		if (i < j - 1)
			printf(" ");
	}
	
	return 0;
}
/* 判断元素在不在数组内 */
int isin(int x, int d[])
{
	int i;
		
	for (i = 0; i < MAXLENGTH; i++) {
		if (x == d[i])
			return 1;
	}
	return 0;
}
/* 冒泡排序法 */
void sort_d(int d[], int len)
{
	int i, j, temp;
	
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 -i; j++) {
			if (d[j] < d[j+1]) {
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}
}


