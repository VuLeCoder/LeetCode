class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        vector<bool> check(n+1, false);
        for(int num : banned)
            if(num <= n)
                check[num] = true;
        
        int cnt = 0, sum = 0;
        for(int i=1; i<=n; ++i)
            if(!check[i] && sum + i <= maxSum)
                sum  += i, cnt++;
        return cnt;
    }
};
