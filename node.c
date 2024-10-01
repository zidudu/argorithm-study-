#include <stdio.h>
#include "node.h"
#include "bst.h"
//중위 순회하며 출력
//중위 순회
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->left);
	}
}