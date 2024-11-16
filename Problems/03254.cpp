class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int check = 0;
        int n = nums.size();
        for(int i=1; i<k; ++i)
            if(nums[i] != nums[i-1] + 1)
                check++;

        vector<int> res;
        if(check == 0) res.push_back(nums[k-1]);
        else res.push_back(-1);

        for(int i=k; i<n; ++i)
        {
            if(nums[i-k]+1 != nums[i-k+1]) check--;

            if(nums[i-1]+1 != nums[i]) check++;

            if(check == 0) res.push_back(nums[i]);
            else res.push_back(-1);
        }

        return res;
    }
};
