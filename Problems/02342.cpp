class Solution {
private:
    int sum_digits(int n)
    {
        int s = 0;
        while(n)
        {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int maximumSum(vector<int>& nums)
    {
        vector<vector<int>> mp(82, vector<int>(0));
        for(int num : nums) mp[sum_digits(num)].push_back(num);

        for(int i=1; i<82; ++i)
            if(mp[i].size() > 2)
                sort(mp[i].begin(), mp[i].end(), greater<int>());
        
        int ans = -1;
        for(int i=1; i<82; ++i)
            if(mp[i].size() > 1)
                ans = max(ans, mp[i][0] + mp[i][1]);
        return ans;
    }
};
