#include"stack.h"
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>

// 初始化栈 
void StackInit(Stack* ps) {
	ps->_a = (STDataType*)malloc(3 * sizeof(STDataType));
	ps->_capacity = 3;
	ps->_top = 1;
}

//扩容
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

// 入栈 
void StackPush(Stack* ps, STDataType data) {
	dilatate(ps);
	ps->_a[ps->_top-1] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps) {
	assert(ps);
	ps->_top--;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps) {
	return ps->_a[ps->_top-1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps) {
	return ps->_top-1;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps) {
	if (ps->_top==1) {
		return 0;
	}
	else {
		return ps->_top-1;
	}
}

// 销毁栈 
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