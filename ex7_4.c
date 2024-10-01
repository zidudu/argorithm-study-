#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bst.h"

// �޴� ��� �Լ�
void menu(void) {
	printf("\n*-----------------*\n");
	printf("\t 1 : Ʈ�� ���\n");
	printf("\t 2 : ���� ����\n");
	printf("\t 3 : ���� ����\n");
	printf("\t 4 : ���� Ž��\n");
	printf("\t 5 : ����\n");
	printf("*-----------------*\n");
	printf("���ϴ� �޴��� �����ϼ��� : ");
}

void clear_input_buffer() {
	// �Է� ���ۿ� ���� ���ڸ� ��� �����ϴ� �Լ�
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main() {
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char choice, key;

	// ��� G�� ��Ʈ ���� ����
	root = insertBSTNode(root, 'G');
	insertBSTNode(root, 'I');
	insertBSTNode(root, 'H');
	insertBSTNode(root, 'D');
	insertBSTNode(root, 'B');
	insertBSTNode(root, 'M');
	insertBSTNode(root, 'N');
	insertBSTNode(root, 'A');
	insertBSTNode(root, 'J');
	insertBSTNode(root, 'E');
	insertBSTNode(root, 'Q');

	while (1) {
		// �޴� ���
		menu();

		// �޴� ���� �Է�
		scanf("%c", &choice);
		clear_input_buffer();  // �Է� �� ���۸� ���

		switch (choice - '0') {
		case 1:
			printf("\t[���� Ʈ�� ���] ");
			displayInorder(root);
			printf("\n");
			break;
		case 2:
			printf("\t[���� ����] ������ ���ڸ� �Է��ϼ��� : ");
			scanf("%c", &key);
			clear_input_buffer();  // �Է� �� ���۸� ���
			insertBSTNode(root, key);
			break;
		case 3:
			printf("\t[���� ����] ������ ���ڸ� �Է��ϼ��� : ");
			scanf("%c", &key);
			clear_input_buffer();  // �Է� �� ���۸� ���
			deleteBSTNode(root, key);
			break;
		case 4:
			printf("ã�� ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			clear_input_buffer();  // �Է� �� ���۸� ���
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("\n ã�� Ű %c�� ���� Ʈ���� �ֽ��ϴ�!", foundedNode->key);
			else
				printf("\n ã�� Ű %c�� ���� Ʈ���� �����ϴ�!", key);
			break;
		case 5:
			return;
		default:
			printf("\n �߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			break;
		}
	}
}
