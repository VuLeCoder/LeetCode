class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> indexSt;
        indexSt.push(0);
        for(int i=1; i<n; ++i)
            if(nums[i] < nums[indexSt.top()]) 
                indexSt.push(i);

        int ramp = 0;
        for(int i=n-1; i>=0; --i)
        {
            while(!indexSt.empty() && i <= indexSt.top()) indexSt.pop();
            while(!indexSt.empty() && nums[i] >= nums[indexSt.top()])
            {
                ramp = max(ramp, i - indexSt.top());
                indexSt.pop();
            }
            if(indexSt.empty()) break;
        }
        return ramp;
    }
};
