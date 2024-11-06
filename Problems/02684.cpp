class Solution {
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int N = grid.size(), M = grid[0].size();
        int dx[] = {-1, 0, 1};
        int dy[] = { 1, 1, 1};
        int MAX = 0;

        vector<vector<int>> dp(N, vector<int>(M, 0));
        for(int j=0; j<M; ++j)
            for(int i=0; i<N; ++i)
                if(dp[i][j] > 0 || j == 0)
                    for(int k=0; k<3; ++k)
                        if(i+dx[k] >= 0 && i+dx[k] < N && j+dy[k] < M && grid[i+dx[k]][j+dy[k]] > grid[i][j])
                        {
                            dp[i+dx[k]][j+dy[k]] = max(dp[i+dx[k]][j+dy[k]], dp[i][j] + 1);
                            MAX = max(MAX, dp[i+dx[k]][j+dy[k]]);
                        }
        return MAX;
    }
};
