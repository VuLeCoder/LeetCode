class Solution {
private:
    int n, ans;
    void backtrack(int sum, vector<int>& nums, int target, int index)
    {
        if(index == n)
        {
            if(sum == target) ans++;
            return;
        }

        backtrack(sum + nums[index], nums, target, index+1);
        backtrack(sum - nums[index], nums, target, index+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        n = nums.size();
        ans = 0;
        backtrack(0, nums, target, 0);
        return ans;
    }
};
