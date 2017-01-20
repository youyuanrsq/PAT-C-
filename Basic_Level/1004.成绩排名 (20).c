/*
1004. 成绩排名 (20)
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
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：每个测试输入包含1个测试用例，格式为
  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/
#include<stdio.h>

int main(void)
{
	char number[100][10];				/* 存储学号 */	
	char name[100][10];					/* 存储姓名 */
	int score[100];						/* 存储分数 */	
	int i, n;
	int high_stu;
	int low_stu;
	int high_i;
	int low_i;
	
	scanf("%d", &n);
	scanf("%s %s %d", &name[0][0], &number[0][0], &score[0]);
	high_stu = score[0];
	low_stu = score[0];
	high_i = low_i = 0;
	
	for (i = 1; i < n; i++) {
		scanf("%s %s %d", &name[i][0], &number[i][0], &score[i]);
		if (high_stu < score[i]) {
			high_stu = score[i];
			high_i = i;
		}
		if (low_stu > score[i]) {
			low_stu = score[i];
			low_i = i;
		}
	}
	
	printf("%s %s %d\n", &name[high_i][0], &number[high_i][0], &score[high_i]);
	printf("%s %s %d\n", &name[low_i][0], &number[low_i][0], &score[low_i]);
	return 0;
}
