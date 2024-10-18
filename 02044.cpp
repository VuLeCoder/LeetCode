class Solution {
public:
    void solve(const vector<int>& nums, int calc, int index, int Max, int &ans)
    {
        if(index == nums.size()) 
        {
            if(calc == Max) ans++;
            return;
        }

        solve(nums, calc | nums[index], index+1, Max, ans);

        solve(nums, calc, index+1, Max, ans);
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int ans = 0, Max = 0;
        for (int num : nums) Max |= num;
        solve(nums, 0, 0, Max, ans);
        return ans;
    }
};
