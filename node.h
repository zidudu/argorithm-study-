#pragma once
typedef char element;

//���� Ʈ�� ���
typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

//���� ��ȸ
void displayInorder(treeNode* root);