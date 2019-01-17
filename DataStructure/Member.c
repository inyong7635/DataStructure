#include "Member.h"
#include<stdio.h>
#include<stdlib.h>

int MemberNoCmp(const Member * x, const Member * y)
{
	if (x->no > y->no) {
		return 1;
	}
	else if (x->no == y->no) {
		return 0;
	}
	else {
		return -1;
	}
	
}

int MemberNameCmp(const Member * x, const Member * y)
{
	return strcmp(x->name, y->name);
}

void PrintMember(const Member * x)
{
	printf("��ȣ : %d, �̸� : %s ", x->no, x->name);
}

void PirntLnMember(const Member * x)
{
	printf("��ȣ : %d, �̸� : %s\n", x->no, x->name);
}

Member ScanMember(const char * message, int sw)
{
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & MEMBER_NO) {
		printf("��ȣ : ");
		scanf_s("%d", &temp.no, sizeof(int));
	}
	if (sw & MEMBER_NAME) {
		printf("�̸� : ");
		scanf_s("%s", temp.name, sizeof(temp.name));
	}
	return temp;
}
