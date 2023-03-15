/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		queue<TreeNode*> node;
		if (root != nullptr)
		{
			node.push(root); //root node;

			while (node.front() != nullptr)
			{
				TreeNode* n1 = node.front();
				node.pop();
				node.push(n1->left);
				node.push(n1->right);
			}

			while (!node.empty())
			{
				if (node.front() != nullptr)return false;
				node.pop();
			}

		}

		return true;
	}
};