#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<locale>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType1;
typedef struct LNode //栈元素节点
{
	ElemType1 data; //数据
	struct LNode* next; //指向下一个节点
}LNode, * LinkStack;
Status InitStack(LinkStack& S) //链式栈初始化
{
	S = (LNode*)malloc(sizeof(LNode));
	if (S == NULL) exit(0);
	S->next = NULL;
	return OK;
}
Status GetTop(LinkStack S, ElemType1& e) //链式栈获取栈顶元素
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	return OK;
}
Status Push(LinkStack& S, ElemType1 e) //链式栈进栈
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) exit(0);
	p->data = e;
	p->next = S->next;
	S->next = p;
	return OK;
}
Status Pop(LinkStack& S, ElemType1& e) //链式栈出栈
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	LNode* p = S->next;
	S->next = p->next;
	free(p);
	return OK;
}
typedef float ElemType2;
typedef struct LNode2 //栈元素节点
{
	ElemType2 data; //数据
	struct LNode2* next; //指向下一个节点
}LNode2, * LinkStack2;
Status InitStack2(LinkStack2& S) //链式栈初始化
{
	S = (LNode2*)malloc(sizeof(LNode2));
	if (S == NULL) exit(0);
	S->next = NULL;
	return OK;
}
Status GetTop2(LinkStack2 S, ElemType2& e) //链式栈获取栈顶元素
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	return OK;
}
Status Push2(LinkStack2& S, ElemType2 e) //链式栈进栈
{
	LNode2* p = (LNode2*)malloc(sizeof(LNode2));
	if (p == NULL) exit(0);
	p->data = e;
	p->next = S->next;
	S->next = p;
	return OK;
}
Status Pop2(LinkStack2& S, ElemType2& e) //链式栈出栈
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	LNode2* p = S->next;
	S->next = p->next;
	free(p);
	return OK;
}
char ComparePriority(ElemType1 e1, ElemType1 e2) //当前操作符与前一个操作符的比较
{
	int i, j;
	//设计优先级表
	switch (e1) //不同的操作符对应不同的下标
	{
	case '+':
		i = 0;
		break;
	case '-':
		i = 1;
		break;
	case '*':
		i = 2;
		break;
	case '/':
		i = 3;
		break;
	case '(':
		i = 4;
		break;
	case ')':
		i = 5;
		break;
	case '#':
		i = 6;
		break;
	default:
		break;
	}
	switch (e2)
	{
	case '+':
		j = 0;
		break;
	case '-':
		j = 1;
		break;
	case '*':
		j = 2;
		break;
	case '/':
		j = 3;
		break;
	case '(':
		j = 4;
		break;
	case ')':
		j = 5;
		break;
	case '#':
		j = 6;
		break;
	default:
		break;
	}
	char prior[7][7]; //用二维数组存放当前元素和栈顶元素优先级比较的结果
	prior[0][0] = '>'; prior[0][1] = '>'; prior[0][2] = '<'; prior[0][3] = '<'; prior[0][4]
		= '<'; prior[0][5] = '>'; prior[0][6] = '>';
	prior[1][0] = '>'; prior[1][1] = '>'; prior[1][2] = '<'; prior[1][3] = '<'; prior[1][4]
		= '<'; prior[1][5] = '>'; prior[1][6] = '>';
	prior[2][0] = '>'; prior[2][1] = '>'; prior[2][2] = '>'; prior[2][3] = '>'; prior[2][4]
		= '<'; prior[2][5] = '>'; prior[2][6] = '>';
	prior[3][0] = '>'; prior[3][1] = '>'; prior[3][2] = '>'; prior[3][3] = '>'; prior[3][4]
		= '<'; prior[3][5] = '>'; prior[3][6] = '>';
	prior[4][0] = '<'; prior[4][1] = '<'; prior[4][2] = '<'; prior[4][3] = '<'; prior[4][4]
		= '<'; prior[4][5] = '='; prior[4][6] = '0';
	prior[5][0] = '>'; prior[5][1] = '>'; prior[5][2] = '>'; prior[5][3] = '>'; prior[5][4]
		= '0'; prior[5][5] = '>'; prior[5][6] = '>';
	prior[6][0] = '<'; prior[6][1] = '<'; prior[6][2] = '<'; prior[6][3] = '<'; prior[6][4]
		= '<'; prior[6][5] = '0'; prior[6][6] = '=';
	return prior[i][j]; //返回栈顶元素和当前元素的优先级比较结果
}
//将字符数字转换为十进制数的函数
float Atoi(char* str, int len)
{
	assert(str != NULL);
	float x = 0;
	int i = 0;
	int flag = 1;//符号位
	int tmp = 0;
	for (; i < len; i++)
	{
		if (str[i] == '-')
		{
			flag = -1;
		}
		if (isdigit(str[i]))
		{
			str[i] -= '0';
			tmp = tmp * 10 + str[i];
		}
	}
	x = tmp * flag;
	return x;
}
float Operate(float a, char theta, float b) //根据操作符 theta 对两个数进行运算
{
	float m; //保存计算结果
	switch (theta)
	{
	case '+':
		m = a + b;
		break;
	case '-':
		m = a - b;
		break;
	case '*':
		m = a * b;
		break;
	case '/':
		m = a / b;
		break;
	default:
		break;
	}
	return m;
}
float CalculateExpression(char* str) //表达式求值算法
{
	//利用 OPND 和 OPTR 栈进行算数表达式求值
	LinkStack OPTR;
	LinkStack2 OPND;
	InitStack2(OPND);
	InitStack(OPTR);
	Push(OPTR, '#'); //将表达式结束符'#'压入 OPTR 栈
	//依次读入表达式的每个字符
	int i = 0;
	int j = 0;
	char str1[20];
	ElemType1 theta1;
	ElemType1 theta;
	GetTop(OPTR, theta1);
	float data;
	int flag = 0;
	float a, b;
	char s;
	while (str[i] != '#' || theta1 != '#')
	{
		//如果是操作数压入 OPND 栈
		if (str[i] >= '0' && str[i] <= '9')
		{
			str1[j] = str[i];
			j++;
			i++; //i 移动到下一个位置
			if (str[i] < '0' || str[i] > '9')
			{
				flag = 1;
			}
			if (flag == 1 && j > 0)
			{
				data = Atoi(str1, j);;
				Push2(OPND, data);
				flag = 0;
				j = 0;
			}
		}
		else
		{
			GetTop(OPTR, theta1); //查看 OPTR 运算符 theta1
			//按照优先级表对栈顶元素 theta1 和当前元素进行比较
			s = ComparePriority(theta1, str[i]);
			switch (s)
			{
			case '<': //栈顶运算优先级低，则当前运算压栈
				Push(OPTR, str[i]);
				i++;
				break;
			case '>': //栈顶运算优先级高，则进行计算，计算结果压入 OPND 栈
				Pop(OPTR, theta);
				Pop2(OPND, b);
				Pop2(OPND, a);
				Push2(OPND, Operate(a, theta, b));
				break;
			case '=':
				Pop(OPTR, theta);
				i++;
				break;
			default:
				break;
			}
		}
		GetTop(OPTR, theta1);
	}
	float result;
	GetTop2(OPND, result);
	return result;
}
int main()
{
	char str[20];
	printf("输入算术表达式(以‘#’结尾):");
	gets_s(str);
	float result;
	result = CalculateExpression(str);
	printf("结果为（保留两位小数）：%.2f\n", result);
	system("pause");
	return 0;
}