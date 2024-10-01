
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

//���� Ž�� Ʈ������ Ű ���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		//x�� ���� ���麸�� �۴ٸ�
		if (x < p->key) p = p->left;
		//���ٸ�
		else if (x == p->key) return p;
		//x�� ���� ���麸�� ũ�ٸ�
		else p = p->right;
	}
	//ã�� ���� ���ٸ�
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

//������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertBSTNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		//���ο� ��忡 x���� �ְ� ���� ������ �����ʹ� NULL�� �ʱ�ȭ
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	//x�� ��� ������ �۴ٸ� p�� ���� �����Ϳ� ������ ��带 ����
	else if (x < p->key) p->left = insertBSTNode(p->left, x); //�ٽ� �Լ��� ȣ���ؼ� x���� �� ��带 ����� p->left�� ��ȯ
	else if (x > p->key) p->right = insertBSTNode(p->right, x); //���ϵ���
	//���� Ű�� ������ �ߺ� �ȵ�.
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}
//��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	//������ ����� ��ġ Ž��
	while ((p!=NULL)&&(p->key!=key)) //p�� ��尡 �ְ�, p���� x���� ���� �ʴٸ� ����
	{
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	//���� ��� ���� ���
	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!");
		return;
	}
	//���� ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) { //�θ� ��尡 NULL�� �ƴϸ� ����
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		//�θ� ��尡 NULL�̸� root �κ��� �� NULL�� ����
		//�Ѹ���� while ������ p�� NULL�̸� parent�� �׳� NULL�� �ֱ� ������ root�� NULL �� ��ü��� ����
		else root = NULL;
	}
	//���� ��尡 �ڽ� ��带 �� �� ���� ���
	// p�� �����̳� ������ �� �ϳ��� NULL�� ��쿡 ������
	else if ((p->left == NULL) || (p->right == NULL)) {
		//p�� ���� ��尡 NULL�� �ƴϸ� child�� ����Ű�� �ּҿ� p�� ���� ��带 ����Ŵ
		if (p->left != NULL) child = p->left;
		//child�� p ������ ��� ����Ŵ
		else child = p->right;

		//�θ� ��尡 NULL�� �ƴ� ���
		if (parent != NULL) {
			//�θ� ��� ���ʿ� p�� �ִٸ� �θ� �����ʿ� child ����. �Ѹ���� p�� ����Ű�� ���� ���� �θ� ��尡 p�� �ڽĳ�带 ����Ŵ
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		//�θ� ��尡 NULL�̸� root�� �׳� child�� ��������
		else root = child;
	}
	else {
		succ_parent = p;
		succ = p->left;
		//p�� ���� ��忡 succ�� �ְ�, succ�� ������ ��尡 �ִٸ� succ_parent�� succ�� ����. 
		// succ�� ������ ����̰� succ_parent�� ������ ����� �θ� �����
		//succ�� ������ ��尡 ���ٸ� �׳� succ�� ������ ����� ��
		while (succ->right != NULL) {
			//succ_parent�� succ�� ����
			succ_parent = succ;
			//
			succ = succ->right;
		}
		//�θ� ��� ���� ��忡 succ�� �ִٸ� �θ� ��� ���� ��忡 succ ���� ��带 ����. 
		// �Ѹ���� succ�� ���� succ �θ�� succ �ڽ� ��带 �̾����. �ٵ� succ �ڽ� ��� ������ �� NULL�� �ؼ� succ�� ����
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		//p ���� succ ��
		p->key = succ->key;
		//p�� suuc�� ����
		p = succ;
	}
	//p �޸� ����
	free(p);
	
	










}