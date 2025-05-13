#include <iostream>
#include <cstring>
using namespace std;
struct TreeNode
{
	char key;
	struct TreeNode* leftchild;
	struct TreeNode* rightchild;
};

 TreeNode * createnode(char value)
{
	TreeNode* temp = new TreeNode;
	temp->key = value;
	temp->leftchild = NULL;
	temp->rightchild = NULL;
	return temp;
}
 void inSertNode(TreeNode* node, char value1,char value2,char value3)
 {
	 node->key = value1;
	 if (value2 != '.')
	 {
		 node->leftchild = createnode(value2);
	 }
	 if (value3 != '.')
	 {
		 node->rightchild = createnode(value3);
	 }
 }
 TreeNode* SearchNode(TreeNode* node, char search)
 {
	 if (node != NULL)
	 {
		 if (node->key == search)
		 {
			 return node;
		 }
		 else
		 {
			 TreeNode* nodesearh = SearchNode(node->leftchild, search);
			 if (nodesearh != NULL)
			 {
				 return nodesearh;
			  }
			 return SearchNode(node->rightchild, search);
		 }
	 }
	 return NULL;
 }
 void PreOrder(TreeNode* node)
 {
	 if (node == NULL)
	 {
		 return;
	 }
	 cout << node->key;
	 PreOrder(node->leftchild);
	 PreOrder(node->rightchild);
 }

 void inOrder(TreeNode* node)
 {
	 if (node == NULL)
	 {
		 return;
	 }
	 inOrder(node->leftchild);
	 cout << node->key;
	 inOrder(node->rightchild);
 }
 void postOrder(TreeNode* node)
 {
	 if (node == NULL)
	 {
		 return ;
	 }
	 postOrder(node->leftchild);
	 postOrder(node->rightchild);
	 cout << node->key;
 }
 void FreeTree(TreeNode* node)
 {
	 if (node)
	 {
		 FreeTree(node->leftchild);
		 FreeTree(node->rightchild);
		 delete node;
	 }
 }
 int main(void)
 {
	 int n;
	 TreeNode * headnode = createnode(NULL);
	 TreeNode * search;
	 cin >> n;
	 char a1, a2, a3;
	 //노드삽입하기
	 for (int i = 0; i < n; i++)
	 {
		 cin >> a1 >> a2 >> a3;
		 search = SearchNode(headnode, a1);
		 if (search != NULL)
		 {
			 inSertNode(search, a1, a2, a3);
		 }
		 else
		 {
			 inSertNode(headnode, a1, a2, a3);
		 }
	 }
	 //노드출력하기
	 PreOrder(headnode);
	 cout << endl;
	 inOrder(headnode);
	 cout << endl;
	 postOrder(headnode);
	 cout << endl;
	 FreeTree(headnode);                  //동적할당으로 만들어준 트리 동적할당해제
	 return 0;
 }