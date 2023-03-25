class Solution {
public:
	bool equal(TreeNode* n1, TreeNode* n2)
	{
		//n1,n2�� null�� ������
		if (!n1 || !n2) return n1 == n2;

		//n1,n2 �� ���� �ƴҶ�
		if (n1->val == n2->val)
		{
			return (equal(n1->left, n2->right) && equal(n2->left, n1->right));
		}
		return false;
	}
	bool isSymmetric(TreeNode* root) {

		return equal(root->left, root->right);
	}
};