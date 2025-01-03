class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        long long sumL = 0, sumR = 0;
        for(int num : nums) sumR += num;
        
        int ans = 0;
        for(int i=0; i<nums.size()-1; ++i)
        {
            sumL += nums[i], sumR -= nums[i];
            if(sumL >= sumR) ans++;
        }
        return ans;
    }
};
