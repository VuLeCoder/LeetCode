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
    int Max = 0;
    vector<vector<int>> arr;
    void splitTree(TreeNode *root, int level)
    {
        arr[level].push_back(root->val);
        Max = max(Max, root->val);
        if(root->left != nullptr) splitTree(root->left, level+1);
        if(root->right != nullptr) splitTree(root->right, level+1);
    }

public:
    int minimumOperations(TreeNode* root)
    {
        arr.resize(100001, vector<int>(0));
        splitTree(root, 0);

        vector<int> pos(Max+1, 0);
        int n, ans = 0, cnt = 0;
        for(vector<int> v : arr)
        {
            n = v.size();
            vector<int> a(n);
            for(int i=0; i<n; ++i) a[i] = v[i], pos[v[i]] = i;
            sort(a.begin(), a.end());

            for(int i=0; i<n; ++i)
                if(v[i] != a[i])
                {
                    ans += 1;
                    pos[v[i]] = pos[a[i]];
                    pos[a[i]] = i;
                    swap(v[i], v[pos[v[i]]]);
                }
        }
        return ans;
    }
};
