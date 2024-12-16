class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = nums.size();
        for(int i=0; i<n; ++i) pq.push({nums[i], i});

        vector<int> ans(nums);
        while(k--)
        {
            int index = pq.top().second;
            int value = pq.top().first;
            pq.pop();

            ans[index] = value * multiplier;
            pq.push({ans[index], index});
        }
        return ans;
    }
};
