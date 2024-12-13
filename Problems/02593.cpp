class Solution {
public:
    long long findScore(vector<int>& nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        int n = nums.size();
        for(int i=0; i<n; ++i) pq.push({nums[i], i});

        long long ans = 0;
        vector<bool> check(n, false);
        while(!pq.empty())
        {
            int MinV = pq.top().first, MinI = pq.top().second;
            pq.pop();
            if(check[MinI]) continue;

            ans += MinV;
            check[MinI] = true;
            if(MinI >= 1) check[MinI-1] = true;
            if(MinI < n-1) check[MinI+1] = true;
        }
        return ans;
    }
};
