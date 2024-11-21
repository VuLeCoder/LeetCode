class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        int ans = m*n;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(vector<int> g : guards) grid[g[0]][g[1]] = 2, ans--; 
        for(vector<int> w : walls) grid[w[0]][w[1]] = 3, ans--;

        for(vector<int> g : guards)
        {
            int x = g[0], y = g[1];
            // duyet len tren va xuong duoi
            for(int i=x-1; i>=0; --i)
            {
                if(grid[i][y] == 2 || grid[i][y] == 3) break;
                if(grid[i][y] == 0) ans--;
                grid[i][y] = 1;
            }
            for(int i=x+1; i<m; ++i)
            {
                if(grid[i][y] == 2 || grid[i][y] == 3) break;
                if(grid[i][y] == 0) ans--;
                grid[i][y] = 1;
            }

            // trai va phai
            for(int i=y-1; i>=0; --i)
            {
                if(grid[x][i] == 2 || grid[x][i] == 3) break;
                if(grid[x][i] == 0) ans--;
                grid[x][i] = 1;
            }
            for(int i=y+1; i<n; ++i)
            {
                if(grid[x][i] == 2 || grid[x][i] == 3) break;
                if(grid[x][i] == 0) ans--;
                grid[x][i] = 1;
            }
        }
        return ans;
    }
};
