class Solution {
public:
    int minimumTime(vector<vector<int>>& grid)
    {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mp(n, vector<int>(m, INT_MAX));

        if(grid[0][1] <= 1) pq.push({1, 0, 1});
        if(grid[1][0] <= 1) pq.push({1, 1, 0});
        pq.push({2, 0, 0});

        int dx[] = { 0, 0, 1,-1};
        int dy[] = { 1,-1, 0, 0};

        while(!pq.empty())
        {
            int time = get<0>(pq.top());
            int x = get<1>(pq.top()), y = get<2>(pq.top());
            pq.pop();

            if(time > mp[x][y]) continue;

            for(int i=0; i<4; ++i)
            {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int newTime = time + 1;
                    if(grid[nx][ny] > newTime)
                    {
                        int wait = (grid[nx][ny] - newTime + 1) / 2;
                        newTime += wait * 2;
                    }

                    if(newTime < mp[nx][ny])
                    {
                        mp[nx][ny] = newTime;
                        pq.push({newTime, nx, ny});
                    }
                }
            }
        }
        return mp[n-1][m-1];
    }
};
