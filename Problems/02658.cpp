class Solution {
private:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};
    vector<vector<bool>> isVisited;

    int bfs(vector<vector<int>>& grid, int u, int v)
    {
        queue<pair<int, int>> q;
        q.push({u, v});

        int x, y, nx, ny, ans = 0;
        ans += grid[u][v]; isVisited[u][v] = true;
        while(!q.empty())
        {
            x = q.front().first, y = q.front().second;
            q.pop();

            for(int i=0; i<4; ++i)
            {
                nx = x + dx[i];  ny = y + dy[i];

                if((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m)) continue;
                if(isVisited[nx][ny] || grid[nx][ny] == 0) continue;

                isVisited[nx][ny] = true;
                ans += grid[nx][ny];
                q.push({nx, ny});
            }
        }
        return ans;
    }

public:
    int findMaxFish(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        isVisited.resize(n, vector<bool>(m, false));

        int ans = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(grid[i][j] != 0 && !isVisited[i][j])
                    ans = max(ans, bfs(grid, i, j));
        return ans;
    }
};
