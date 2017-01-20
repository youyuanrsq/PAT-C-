1002. 写出这个数 (20)

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
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu

#include<stdio.h>
#include<string.h>

int main(void)
{
	char input_str[100];
	int sum;
	int i, j, len;
	
	char output_str[10][] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	
	scanf("%s", input_str);
	len = strlen(input_str);
	
	int result_d[len];
	sum = 0;
	
	/* 计算各数相加之和 */
	for (i = 0; i < len; i++) {
		sum += (input_str - '0');
	}
	
	if (sum == 0) {
		printf("%s\n", output_str[0];
		return 0;
	}
	/* 把sum拆分装入数组，先存入的是个位数，后依次存入 */
	j = 0;
	while (sum != 0) {
		result_d[j++] = sum % 10;
		sum /= 10;
	}
	/* 打印输出 */
	for (i = j-1; i >= 0; i--) {
		printf("%s",output_str[result_d[i]]);
		if (i != 0)
			printf(" ");
	}
	return 0;
}
