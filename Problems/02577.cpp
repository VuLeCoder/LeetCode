class Solution {
public:
    int minimumTime(vector<vector<int>>& grid)
    {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
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

            if(visited[x][y] && mp[x][y] <= time) continue;
            visited[x][y] = true;
            mp[x][y] = time;

            for(int i=0; i<4; ++i)
                if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m)
                {
                    if(!visited[x+dx[i]][y+dy[i]])
                    {
                        if(grid[x+dx[i]][y+dy[i]] <= time+1) pq.push({time+1, x+dx[i], y+dy[i]});
                        else
                        {
                            int w = (grid[x+dx[i]][y+dy[i]] - time)/2;
                            pq.push({time+w*2+1, x+dx[i], y+dy[i]});
                        }
                    }
                    else
                    {
                        if(mp[x+dx[i]][y+dy[i]] > time+1)
                            pq.push({time+1, x+dx[i], y+dy[i]});
                    }
                }
        }
        return mp[n-1][m-1];
    }
};
