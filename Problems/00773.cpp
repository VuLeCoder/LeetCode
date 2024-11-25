class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        map<vector<vector<int>>, bool> check;
        queue<tuple<vector<vector<int>>, int, int, int>> q;

        vector<vector<int>> solve = {{1, 2, 3}, {4, 5, 0}};

        int i0, j0;
        for(int i=0; i<2; ++i)
            for(int j=0; j<3; ++j)
                if(board[i][j] == 0)
                {
                    i0 = i, j0 = j;
                    break;
                }
        q.push({board, i0, j0, 0});

        while(!q.empty())
        {
            tuple<vector<vector<int>>, int, int, int> top = q.front();
            q.pop();

            vector<vector<int>> tmp = get<0>(top);
            int cnt = get<3>(top);
            if(tmp == solve) return cnt;

            check[tmp] = true;
            int x = get<1>(top);
            int y = get<2>(top);
            cnt++;
            
            if(x-1 >= 0)
            {
                swap(tmp[x-1][y], tmp[x][y]);
                if(!check[tmp]) q.push({tmp, x-1, y, cnt});
                swap(tmp[x-1][y], tmp[x][y]);
            }

            if(x+1 < 2)
            {
                swap(tmp[x+1][y], tmp[x][y]);
                if(!check[tmp]) q.push({tmp, x+1, y, cnt});
                swap(tmp[x+1][y], tmp[x][y]);                
            }

            if(y-1 >= 0)
            {
                swap(tmp[x][y], tmp[x][y-1]);
                if(!check[tmp]) q.push({tmp, x, y-1, cnt});
                swap(tmp[x][y-1], tmp[x][y]);
            }

            if(y+1 < 3)
            {
                swap(tmp[x][y], tmp[x][y+1]);
                if(!check[tmp]) q.push({tmp, x, y+1, cnt});
                swap(tmp[x][y+1], tmp[x][y]);
            }
        }
        return -1;
    }
};
