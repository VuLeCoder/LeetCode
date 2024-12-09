class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n  = nums.size();
        vector<int> check(n);

        int isValid = 0;
        check[0] = isValid;
        for(int i=1; i<n; ++i)
        {
            if( (nums[i] % 2) == (nums[i-1] % 2) ) isValid++;
            check[i] = isValid;
        }

        n = queries.size();
        vector<bool> ans(n);
        for(int i=0; i<n; ++i)
            ans[i] = (check[queries[i][0]] == check[queries[i][1]]);
        return ans;
    }
};
