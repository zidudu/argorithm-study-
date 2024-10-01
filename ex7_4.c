#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bst.h"

// 메뉴 출력 함수
void menu(void) {
	printf("\n*-----------------*\n");
	printf("\t 1 : 트리 출력\n");
	printf("\t 2 : 문자 삽입\n");
	printf("\t 3 : 문자 삭제\n");
	printf("\t 4 : 문자 탐색\n");
	printf("\t 5 : 종료\n");
	printf("*-----------------*\n");
	printf("원하는 메뉴를 선택하세요 : ");
}

void clear_input_buffer() {
	// 입력 버퍼에 남은 문자를 모두 제거하는 함수
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main() {
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char choice, key;

	// 노드 G를 루트 노드로 삽입
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
		// 메뉴 출력
		menu();

		// 메뉴 선택 입력
		scanf("%c", &choice);
		clear_input_buffer();  // 입력 후 버퍼를 비움

		switch (choice - '0') {
		case 1:
			printf("\t[이진 트리 출력] ");
			displayInorder(root);
			printf("\n");
			break;
		case 2:
			printf("\t[문자 삽입] 삽입할 문자를 입력하세요 : ");
			scanf("%c", &key);
			clear_input_buffer();  // 입력 후 버퍼를 비움
			insertBSTNode(root, key);
			break;
		case 3:
			printf("\t[문자 삭제] 삭제할 문자를 입력하세요 : ");
			scanf("%c", &key);
			clear_input_buffer();  // 입력 후 버퍼를 비움
			deleteBSTNode(root, key);
			break;
		case 4:
			printf("찾을 문자를 입력하세요 : ");
			scanf(" %c", &key);
			clear_input_buffer();  // 입력 후 버퍼를 비움
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("\n 찾는 키 %c가 이진 트리에 있습니다!", foundedNode->key);
			else
				printf("\n 찾는 키 %c가 이진 트리에 없습니다!", key);
			break;
		case 5:
			return;
		default:
			printf("\n 잘못된 입력입니다. 다시 입력하세요.\n");
			break;
		}
	}
}
