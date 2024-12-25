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
    vector<vector<int>> arr;
    void splitTree(TreeNode* root, int level)
    {
        if(!root) return;
        arr[level].push_back(root->val);
        splitTree(root->left, level+1);
        splitTree(root->right, level+1);
    }
public:
    vector<int> largestValues(TreeNode* root)
    {
        arr.resize(10001, vector<int>(0));
        splitTree(root, 0);

        vector<int> ans(0);
        for(vector<int> v : arr)
            if(!v.empty())
            {
                int Max = INT_MIN;
                for(int num : v) Max = max(Max, num);
                ans.push_back(Max);
            }
        return ans;
    }
};
