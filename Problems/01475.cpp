class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> ans(prices);
        
        stack<int> index;
        for(int i=0; i<n; ++i)
        {
            while(!index.empty() && prices[i] <= prices[index.top()])
            {
                ans[index.top()] -= prices[i];
                index.pop();
            }
            index.push(i);
        }
        return ans;
    }
};
