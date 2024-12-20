class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int ans = 0, n = arr.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; ++i)
        {
            int Min = min(arr[i], i);
            int Max = max(arr[i], i);

            bool check = true;
            for(int j=Min; j<=Max; ++j)
                if(res[j] != 0)
                {
                    check = false;
                    break;
                }
            if(check) ans++;

            for(int j=Min; j<=Max; ++j) res[j] = ans;
        }
        return ans;
    }
};
