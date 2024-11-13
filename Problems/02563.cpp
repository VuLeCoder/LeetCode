class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(l < r)
        {
            if(nums[l] + nums[r] > upper) r--;
            else
            {
                int i = l+1, j = r;
                while(i <= j)
                {
                    int mid = (i+j)/2;
                    if(nums[l] + nums[mid] >= lower) j = mid - 1;
                    else i = mid + 1;
                }
                ans += (r - i + 1);
                l++;
            }
        }
        return ans;
    }
};
