#include <stdio.h>
#include "node.h"
#include "bst.h"
//���� ��ȸ�ϸ� ���
//���� ��ȸ
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->left);
	}
}