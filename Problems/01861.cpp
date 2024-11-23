class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n));

        for(int index=0; index<n; ++index)
        {
            int r = m-1;
            while(r >= 0 && box[index][r] != '.') r--;

            int l = r;
            while(l >= 0)
            {
                if(box[index][l] == '*')
                {
                    while(l >= 0 && box[index][l] != '.') l--;
                    r = l;
                }
                else if(box[index][l] == '#')
                {
                    swap(box[index][l], box[index][r]);
                    r--;
                }

                l--;
            }
        }

        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                ans[i][j] = box[n-1-j][i];
        return ans;
    }
};
