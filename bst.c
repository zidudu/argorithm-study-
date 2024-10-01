
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

//이진 탐색 트리에서 키 값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		//x가 기존 노드들보다 작다면
		if (x < p->key) p = p->left;
		//같다면
		else if (x == p->key) return p;
		//x가 기존 노드들보다 크다면
		else p = p->right;
	}
	//찾는 값이 없다면
	printf("\n 찾는 키가 없습니다!");
	return p;
}

//포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertBSTNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		//새로운 노드에 x값을 넣고 왼쪽 오른쪽 포인터는 NULL로 초기화
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	//x가 노드 값보다 작다면 p의 왼쪽 포인터에 삽입할 노드를 연결
	else if (x < p->key) p->left = insertBSTNode(p->left, x); //다시 함수를 호출해서 x에게 줄 노드를 만들고 p->left에 반환
	else if (x > p->key) p->right = insertBSTNode(p->right, x); //이하동일
	//같은 키가 있을때 중복 안됨.
	else printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}
//루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	//삭제할 노드의 위치 탐색
	while ((p!=NULL)&&(p->key!=key)) //p의 노드가 있고, p값이 x값과 같지 않다면 실행
	{
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	//삭제 노드 없는 경우
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!");
		return;
	}
	//삭제 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) { //부모 노드가 NULL이 아니면 실행
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		//부모 노드가 NULL이면 root 부분을 걍 NULL로 만듬
		//한마디로 while 문에서 p가 NULL이면 parent는 그냥 NULL로 있기 때문에 root가 NULL 그 자체라는 거임
		else root = NULL;
	}
	//삭제 노드가 자식 노드를 한 개 가진 경우
	// p의 왼쪽이나 오른쪽 중 하나가 NULL인 경우에 실행함
	else if ((p->left == NULL) || (p->right == NULL)) {
		//p의 왼쪽 노드가 NULL이 아니면 child가 가리키는 주소에 p의 왼쪽 노드를 가리킴
		if (p->left != NULL) child = p->left;
		//child에 p 오른쪽 노드 가리킴
		else child = p->right;

		//부모 노드가 NULL이 아닌 경우
		if (parent != NULL) {
			//부모 노드 왼쪽에 p가 있다면 부모 노드왼쪽에 child 넣음. 한마디로 p가 가리키는 노드는 빼고 부모 노드가 p의 자식노드를 가리킴
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		//부모 노드가 NULL이면 root를 그냥 child로 만들어버럼
		else root = child;
	}
	else {
		succ_parent = p;
		succ = p->left;
		//p의 왼쪽 노드에 succ을 넣고, succ의 오른쪽 노드가 있다면 succ_parent에 succ을 넣음. 
		// succ은 삭제할 노드이고 succ_parent는 삭제할 노드의 부모 노드임
		//succ의 오른쪽 노드가 없다면 그냥 succ이 삭제할 노드라는 거
		while (succ->right != NULL) {
			//succ_parent에 succ을 넣음
			succ_parent = succ;
			//
			succ = succ->right;
		}
		//부모 노드 왼쪽 노드에 succ이 있다면 부모 노드 왼쪽 노드에 succ 왼쪽 노드를 넣음. 
		// 한마디로 succ을 빼고 succ 부모와 succ 자식 노드를 이어버림. 근데 succ 자식 노드 없으면 걍 NULL로 해서 succ을 끊음
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		//p 값에 succ 값
		p->key = succ->key;
		//p에 suuc을 넣음
		p = succ;
	}
	//p 메모리 해제
	free(p);
	
	










}