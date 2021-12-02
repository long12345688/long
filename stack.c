#include"stack.h"
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>

// ��ʼ��ջ 
void StackInit(Stack* ps) {
	ps->_a = (STDataType*)malloc(3 * sizeof(STDataType));
	ps->_capacity = 3;
	ps->_top = 1;
}

//����
void dilatate(Stack* ps) {
	assert(ps);
	if ((ps->_capacity) == (ps->_top)) {
		STDataType* node = (STDataType*)malloc(2*ps->_capacity*sizeof(STDataType));
		if (NULL == node) {
			assert(0);
			return;
		}
		memcpy(node,ps->_a,ps->_top-1);
		free(ps->_a);
		ps->_a = node;
	}
}

// ��ջ 
void StackPush(Stack* ps, STDataType data) {
	dilatate(ps);
	ps->_a[ps->_top-1] = data;
	ps->_top++;
}

// ��ջ 
void StackPop(Stack* ps) {
	assert(ps);
	ps->_top--;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps) {
	return ps->_a[ps->_top-1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps) {
	return ps->_top-1;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps) {
	if (ps->_top==1) {
		return 0;
	}
	else {
		return ps->_top-1;
	}
}

// ����ջ 
void StackDestroy(Stack* ps) {
	if (ps->_a) {
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}	
}

int main() {
	Stack ps;
	StackInit(&ps);
	StackPush(&ps,1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	printf("%d\n", StackEmpty(&ps));
	StackPop(&ps);
	StackPop(&ps);
	printf("%d", StackTop(&ps));
}