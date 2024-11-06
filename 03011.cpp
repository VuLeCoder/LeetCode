class Solution {
public:
    int num_set_bits(int num)
    {
        int ans = 0;
        while(num) 
        { 
            int x = num % 2; 
            num /= 2; 
            ans += (x == 1); 
        }
        return ans; 
    }
    bool canSortArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<pair<int, int>> numsCheck(n);
        for(int i=0; i<n; ++i)
        {
            numsCheck[i].first = nums[i];
            numsCheck[i].second = num_set_bits(nums[i]);
        }

        for(int i=0; i<n-1; ++i)
            if(numsCheck[i].first > numsCheck[i+1].first)
            {
                if(numsCheck[i].second == numsCheck[i+1].second)
                    swap(numsCheck[i], numsCheck[i+1]);
                else return false;
            }
        for(int i=n-1; i>0; --i)
            if(numsCheck[i].first < numsCheck[i-1].first)
            {
                if(numsCheck[i].second == numsCheck[i-1].second)
                    swap(numsCheck[i], numsCheck[i-1]);
                else return false;
            }
        return true;
    }
};
