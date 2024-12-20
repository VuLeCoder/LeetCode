class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size(), ans = 0;
        k *= 2;
        while(r < n)
        {
            if(nums[r] - nums[l] <= k) r++;
            else l++, ans = max(ans, r-l+1);
        }
        ans = max(ans, r-l);
        return ans;
    }
};
