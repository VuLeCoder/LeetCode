class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        map<pair<int, int>, int> mp;

        pq.push({0, 0, 0});

        int dx[] = { 0, 0, 1,-1};
        int dy[] = { 1,-1, 0, 0};

        while(!pq.empty())
        {
            int x = get<1>(pq.top()), y = get<2>(pq.top());
            int remove = get<0>(pq.top());
            pq.pop();

            if(visited[x][y] && mp[{x, y}] <= remove) continue;
            visited[x][y] = true;
            mp[{x, y}] = remove;

            for(int i=0; i<4; ++i)
                if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m)
                {
                    if(!visited[x+dx[i]][y+dy[i]])
                    {
                        if(grid[x+dx[i]][y+dy[i]] == 1) pq.push({remove+1, x+dx[i], y+dy[i]});
                        else pq.push({remove, x+dx[i], y+dy[i]});
                    }
                    else
                    {
                        if(mp[{x+dx[i], y+dy[i]}] > remove)
                            pq.push({remove, x+dx[i], y+dy[i]});
                    }
                }
        }
        return mp[{n-1, m-1}];
    }
};
