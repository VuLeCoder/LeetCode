class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        unordered_map<int, int> cnt;
        vector<int> ans(n, 0);

        if(++cnt[A[0]] > 1) ans[0]++;
        if(++cnt[B[0]] > 1) ans[0]++;
        
        for(int i=1; i<n; ++i)
        {
            if(++cnt[A[i]] > 1) ans[i]++;
            if(++cnt[B[i]] > 1) ans[i]++;
            ans[i] += ans[i-1];
        }
        return ans;
    }
};
