#include"list.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//�������
ListNode* buyCreate(LTDataType n) {
	ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
	newHead->_next = NULL;
	newHead->_prev = NULL;
	newHead->_data = n;
	return newHead;
}

// �������������ͷ���.
ListNode* ListCreate() {
	ListNode* head = buyCreate(-1);
	head->_next = head;
	head->_prev = head;
	return head;
}


// ˫����������
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

// ˫���������
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

// ˫�������ӡ,������Ϊѭ������Ĭ�ϴ�ӡ��ͷ�ڵ�֮ǰ
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

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x) {
	ListNode* cur = buyCreate(x);
	cur->_next = pHead;
	cur->_prev = pHead->_prev;
	cur->_prev->_next = cur;
	pHead->_prev = cur;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_prev;
	cur->_prev->_next = pHead;
	pHead->_prev=cur->_prev;
	free(cur);
	cur->_next = NULL;
	cur->_prev = NULL;
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* cur = buyCreate(x);
	cur->_next = pHead->_next;
	cur->_prev = pHead;
	cur->_next->_prev = cur;
	pHead->_next = cur;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	pHead->_next = cur->_next;
	cur->_next->_prev = pHead;
	free(cur);
	cur->_next = NULL;
	cur->_prev = NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* cur = buyCreate(x);
	cur->_next = pos;
	cur->_prev = pos->_prev;
	pos->_prev->_next = cur;
	pos->_prev = cur;
}


// ˫������ɾ��posλ�õĽڵ�
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