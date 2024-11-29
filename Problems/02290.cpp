class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mp(n, vector<int>(m, INT_MAX));

        pq.push({0, 0, 0});

        int dx[] = { 0, 0, 1,-1};
        int dy[] = { 1,-1, 0, 0};

        while(!pq.empty())
        {
            int x = get<1>(pq.top()), y = get<2>(pq.top());
            int remove = get<0>(pq.top());
            pq.pop();

            if(remove > mp[x][y]) continue;

            for(int i=0; i<4; ++i)
                if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m)
                {
                    int newRemove = remove + grid[x+dx[i]][y+dy[i]];
                    if(newRemove < mp[x+dx[i]][y+dy[i]])
                    {
                        mp[x+dx[i]][y+dy[i]] = newRemove;
                        pq.push({newRemove, x+dx[i], y+dy[i]});
                    }
                }
        }
        return mp[n-1][m-1];
    }
};
