class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        vector<int> mp(100001, 0);
        long long ans = 0, sum = 0;
        
        int n = nums.size(), repeat = 0;
        for(int i=0; i<k; ++i)
        {
            sum += nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) repeat++;
        }
        if(repeat == 0) ans = max(ans, sum);

        for(int i=k; i<n; ++i)
        {
            sum -= nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] >= 1) repeat--;

            sum += nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) repeat++;

            if(repeat == 0) ans = max(ans, sum);
        }
        return ans;
    }
};
