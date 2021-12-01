#include"list.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//创建结点
ListNode* buyCreate(LTDataType n) {
	ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
	newHead->_next = NULL;
	newHead->_prev = NULL;
	newHead->_data = n;
	return newHead;
}

// 创建返回链表的头结点.
ListNode* ListCreate() {
	ListNode* head = buyCreate(-1);
	head->_next = head;
	head->_prev = head;
	return head;
}


// 双向链表销毁
void ListDestory(ListNode** pHead) {
	assert(*pHead);
	ListNode* cur = (*pHead)->_next;
	while (cur->_next!=(*pHead))
	{
		ListPopFront(*pHead);
	}
	free(*pHead);
	(*pHead)->_next = NULL;
	(*pHead)->_prev = NULL;
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur->_next != pHead) {
		if (cur->_data == x) {
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

// 双向链表打印,此链表为循环链表，默认打印至头节点之前
void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	if (cur->_next==pHead) {
		printf("%d",cur->_data);
		return;
	}
	while (cur!=pHead) {
		printf("%d", cur->_data);
		printf("\n");
		cur = cur->_next;
	}
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x) {
	ListNode* cur = buyCreate(x);
	cur->_next = pHead;
	cur->_prev = pHead->_prev;
	cur->_prev->_next = cur;
	pHead->_prev = cur;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_prev;
	cur->_prev->_next = pHead;
	pHead->_prev=cur->_prev;
	free(cur);
	cur->_next = NULL;
	cur->_prev = NULL;
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* cur = buyCreate(x);
	cur->_next = pHead->_next;
	cur->_prev = pHead;
	cur->_next->_prev = cur;
	pHead->_next = cur;
}
// 双向链表头删
void ListPopFront(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	pHead->_next = cur->_next;
	cur->_next->_prev = pHead;
	free(cur);
	cur->_next = NULL;
	cur->_prev = NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* cur = buyCreate(x);
	cur->_next = pos;
	cur->_prev = pos->_prev;
	pos->_prev->_next = cur;
	pos->_prev = cur;
}


// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* cur = pos->_prev;
	cur->_next = pos->_next;
	pos->_next->_prev=cur;
	free(pos);
	pos->_prev = NULL;
	pos->_next = NULL;
}

int main() {
	ListNode* pHead= ListCreate();
	ListPushBack(pHead,1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPrint(pHead);
	printf("\n");
	ListErase(ListFind(pHead, 2));
	ListPrint(pHead);
}