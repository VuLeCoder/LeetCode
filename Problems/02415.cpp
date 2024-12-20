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
private:
    vector<vector<int>> a;

    void preOrder(TreeNode* root, int level)
    {
        if(level % 2 != 0) a[level].push_back(root->val);

        if(root->left != nullptr)
        {
            preOrder(root->left, level+1);
            preOrder(root->right, level+1);
        }
    }

    void solve(TreeNode* root, int level)
    {
        if(level % 2 != 0)
        {
            root->val = a[level].back();
            a[level].pop_back();
        }

        if(root->left != nullptr)
        {
            solve(root->left, level+1);
            solve(root->right, level+1);
        }
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        a.resize(14, vector<int>(0));
        preOrder(root, 0);
        solve(root, 0);
        return root;
    }
};
