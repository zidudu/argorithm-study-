#pragma once
#include "node.h"

//이진 트리 탐색
treeNode* searchBST(treeNode* root, element x);
//이진 트리 삽입
treeNode* insertBSTNode(treeNode* p, element x);
//이진 트리 삭제
void deleteBSTNode(treeNode* root, element key);