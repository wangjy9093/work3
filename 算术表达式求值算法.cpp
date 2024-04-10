#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<locale>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType1;
typedef struct LNode //ջԪ�ؽڵ�
{
	ElemType1 data; //����
	struct LNode* next; //ָ����һ���ڵ�
}LNode, * LinkStack;
Status InitStack(LinkStack& S) //��ʽջ��ʼ��
{
	S = (LNode*)malloc(sizeof(LNode));
	if (S == NULL) exit(0);
	S->next = NULL;
	return OK;
}
Status GetTop(LinkStack S, ElemType1& e) //��ʽջ��ȡջ��Ԫ��
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	return OK;
}
Status Push(LinkStack& S, ElemType1 e) //��ʽջ��ջ
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) exit(0);
	p->data = e;
	p->next = S->next;
	S->next = p;
	return OK;
}
Status Pop(LinkStack& S, ElemType1& e) //��ʽջ��ջ
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	LNode* p = S->next;
	S->next = p->next;
	free(p);
	return OK;
}
typedef float ElemType2;
typedef struct LNode2 //ջԪ�ؽڵ�
{
	ElemType2 data; //����
	struct LNode2* next; //ָ����һ���ڵ�
}LNode2, * LinkStack2;
Status InitStack2(LinkStack2& S) //��ʽջ��ʼ��
{
	S = (LNode2*)malloc(sizeof(LNode2));
	if (S == NULL) exit(0);
	S->next = NULL;
	return OK;
}
Status GetTop2(LinkStack2 S, ElemType2& e) //��ʽջ��ȡջ��Ԫ��
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	return OK;
}
Status Push2(LinkStack2& S, ElemType2 e) //��ʽջ��ջ
{
	LNode2* p = (LNode2*)malloc(sizeof(LNode2));
	if (p == NULL) exit(0);
	p->data = e;
	p->next = S->next;
	S->next = p;
	return OK;
}
Status Pop2(LinkStack2& S, ElemType2& e) //��ʽջ��ջ
{
	if (S->next == NULL) return ERROR;
	e = S->next->data;
	LNode2* p = S->next;
	S->next = p->next;
	free(p);
	return OK;
}
char ComparePriority(ElemType1 e1, ElemType1 e2) //��ǰ��������ǰһ���������ıȽ�
{
	int i, j;
	//������ȼ���
	switch (e1) //��ͬ�Ĳ�������Ӧ��ͬ���±�
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
	char prior[7][7]; //�ö�ά�����ŵ�ǰԪ�غ�ջ��Ԫ�����ȼ��ȽϵĽ��
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
	return prior[i][j]; //����ջ��Ԫ�غ͵�ǰԪ�ص����ȼ��ȽϽ��
}
//���ַ�����ת��Ϊʮ�������ĺ���
float Atoi(char* str, int len)
{
	assert(str != NULL);
	float x = 0;
	int i = 0;
	int flag = 1;//����λ
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
float Operate(float a, char theta, float b) //���ݲ����� theta ����������������
{
	float m; //���������
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
float CalculateExpression(char* str) //���ʽ��ֵ�㷨
{
	//���� OPND �� OPTR ջ�����������ʽ��ֵ
	LinkStack OPTR;
	LinkStack2 OPND;
	InitStack2(OPND);
	InitStack(OPTR);
	Push(OPTR, '#'); //�����ʽ������'#'ѹ�� OPTR ջ
	//���ζ�����ʽ��ÿ���ַ�
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
		//����ǲ�����ѹ�� OPND ջ
		if (str[i] >= '0' && str[i] <= '9')
		{
			str1[j] = str[i];
			j++;
			i++; //i �ƶ�����һ��λ��
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
			GetTop(OPTR, theta1); //�鿴 OPTR ����� theta1
			//�������ȼ����ջ��Ԫ�� theta1 �͵�ǰԪ�ؽ��бȽ�
			s = ComparePriority(theta1, str[i]);
			switch (s)
			{
			case '<': //ջ���������ȼ��ͣ���ǰ����ѹջ
				Push(OPTR, str[i]);
				i++;
				break;
			case '>': //ջ���������ȼ��ߣ�����м��㣬������ѹ�� OPND ջ
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
	printf("�����������ʽ(�ԡ�#����β):");
	gets_s(str);
	float result;
	result = CalculateExpression(str);
	printf("���Ϊ��������λС������%.2f\n", result);
	system("pause");
	return 0;
}