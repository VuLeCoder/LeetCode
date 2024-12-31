class Solution {
private:
    vector<int> dp;
    vector<bool> isDay;

    int solve(int curr, vector<int>& costs)
    {
        if(curr >= isDay.size()) return 0;
        if(!isDay[curr]) return solve(curr + 1, costs);
        
        if(dp[curr] != -1) return dp[curr];

        int onePass = costs[0] + solve(curr + 1, costs);
        int sevenPass = costs[1] + solve(curr + 7, costs);
        int thirtyPass = costs[2] + solve(curr + 30, costs);

        dp[curr] = min(onePass, min(sevenPass, thirtyPass));
        return dp[curr];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        dp.resize(days.back() + 1, -1);

        isDay.resize(days.back() + 1, false);
        for(int day : days) isDay[day] = true;

        return solve(1, costs);
    }
};
