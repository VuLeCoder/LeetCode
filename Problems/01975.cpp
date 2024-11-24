class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int cnt = 0;
        int Min = INT_MAX;
        
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
            {
                if(matrix[i][j] < 0) cnt++;
                Min = min(Min, abs(matrix[i][j]));
            }
        
        long long sum = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                sum += abs(matrix[i][j]);

        if(cnt % 2 != 0) sum -= Min*2;
        return sum;
    }
};
