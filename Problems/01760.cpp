class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;

        while(l < r)
        {
            int mid = l + (r-l)/2;
            int cnt = 0, check = 1;
            for(int num : nums)
            {
                int step = num/mid;
                if(step * mid < num) step+=1;
                cnt += step-1;

                if(cnt > maxOperations) {check = 0; break;}
            }
            if(check == 1) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
