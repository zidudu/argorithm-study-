#pragma once
typedef char element;

//이진 트리 노드
typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

//중위 순회
void displayInorder(treeNode* root);