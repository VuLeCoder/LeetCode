class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);

        if(k == 0) return ans;

        int tmp = 0;
        if(k > 0)
            for(int i=1; i<=k; ++i)
                tmp += code[i];
        else
            for(int i=n-1; i>=n+k; --i)
                tmp += code[i];
        
        for(int i=0; i<n; ++i)
        {
            ans[i] = tmp;
            if(k > 0) tmp += code[(i+k+1)%n], tmp -= code[(i+1)%n];
            else tmp += code[i], tmp -= code[(n+k+i)%n];
        }
        return ans;
    }
};
