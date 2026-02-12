/*
Title: 数据结构 - 链表实现
Description: 本源文件实现了链表各节点的定义、头插法、尾插法、任意位置插入、任意位置删除，以及反转整个链表。
Author: DevCherry
Time: 2026-02-12
Links: https://www.bilibili.com/video/BV1Fv4y1f7T1
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 定义节点结构体
struct Node {
	int data;
	Node* next;
};

// 插入：头插法
void headInsert(Node* &head, int x) {
	Node* temp = new Node;
	temp->data = x;
	temp->next = head;
	head = temp;
}

// 插入：尾插法
void endInsert(Node* &head, int x) {
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) { head = temp; return; }

	Node* pre = head;
	while (pre->next != NULL) {
		pre = pre->next;
	}
	pre->next = temp;
}

// 获取链表长度
int length(Node* head) {
	Node* temp = head;
	int i = 0;
	while (temp != NULL) {
		i = i + 1;
		temp = temp->next;
	}
	return i;
}

// 获取链表中某个位置的指针 [已弃用]
Node* pointer(Node* head, int index) {
	Node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}

// 插入：任意位置插入
void Insert(Node* &head, int x, int index) {
	if (index < 0) return;
	if (index > (length(head) - 1) + 1) return;
	if (index == 0) { headInsert(head, x); return; }
	
	Node* temp = new Node;
	temp->data = x;

	Node* pre = head;
	for (int i = 0; i < index - 1; i++) {
		pre = pre->next;
	}

	temp->next = pre->next;
	pre->next = temp;
}

// 删除：删除任意位置的节点
void Delete(Node* &head, int index) {
	if (head == NULL) return;
	if (index > length(head) - 1) return;
	Node* pre = head;
	Node* toDelete;
	if (index == 0) {
		toDelete = pre;
		head = pre->next;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			pre = pre->next;
		}
		toDelete = pre->next;
		pre->next = (pre->next)->next;
	}
	delete toDelete;
	//(pre->next)->next = NULL; 典型错误
}

// 打印：打印整个链表
void Print(Node* head) {
	if (head == NULL) return;
	Node* temp = head;
	printf("List:");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// 反转：用迭代方式实现反转链表
void Reverse(Node* &head) {
	if (length(head) == 0) return;
	if (length(head) == 1) return;
	if (length(head) == 2) {
		(head->next)->next = head;
		head->next = NULL;
		return;
	}
	else {
		Node* pre = head;
		Node* current = head->next;
		Node* next = (head->next)->next;
		head->next = NULL;
		while (1) {
			current->next = pre;
			pre = current;
			current = next;
			if (current == NULL) break;
			next = next->next;
		}
		head = pre;
		return;
	}
}

// 反转：用递归方式实现反转链表

int main() {
	Node* head = NULL;
	Print(head);
	endInsert(head, 1);
	endInsert(head, 2);
	endInsert(head, 3);
	endInsert(head, 4);
	Print(head);
	Reverse(head);
	Print(head);
	return 0;
}