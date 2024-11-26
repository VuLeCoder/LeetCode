class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<bool> isChampion(n, true);

        int m = edges.size();
        for(int i=0; i<m; ++i) isChampion[edges[i][1]] = false;

        int cnt = 0, champion;
        for(int i=0; i<n; ++i)
            if(isChampion[i])
            {
                champion = i;
                cnt++;
            }

        return cnt > 1 ? -1 : champion;
    }
};
