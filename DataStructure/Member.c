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
	printf("번호 : %d, 이름 : %s ", x->no, x->name);
}

void PirntLnMember(const Member * x)
{
	printf("번호 : %d, 이름 : %s\n", x->no, x->name);
}

Member ScanMember(const char * message, int sw)
{
	Member temp;
	printf("%s하는 데이터를 입력하세요.\n", message);
	if (sw & MEMBER_NO) {
		printf("번호 : ");
		scanf_s("%d", &temp.no, sizeof(int));
	}
	if (sw & MEMBER_NAME) {
		printf("이름 : ");
		scanf_s("%s", temp.name, sizeof(temp.name));
	}
	return temp;
}
