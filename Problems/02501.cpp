class Solution {
public:
    int longestSquareStreak(vector<int>& nums)
    {
        unordered_map<int, bool> mp;
        sort(nums.begin(), nums.end());
        for(int num : nums) mp[num] = true;

        int ans = 1;
        for(int i=0; i<nums.size(); ++i)
            if(mp[nums[i]])
            {
                int l = 0, num = nums[i];
                while(mp[num])
                {
                    l++;
                    mp[num] = false;
                    if(num > 317) break;
                    num *= num;
                }
                ans = max(ans, l);
            }

        return ans == 1 ? -1 : ans;
    }
};
