class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        int m = queries.size();
        vector<int> ans(m);
        vector<vector<int>> adj(n, vector<int>(0));

        for(int i=0; i<m; ++i)
        {
            vector<bool> vi(n, false);
            adj[queries[i][0]].push_back(queries[i][1]);
            queue<pair<int, int>> q;
            q.push({0, 0});
            vi[0] = true;

            int res = n-1;
            while(!q.empty())
            {
                int top = q.front().first;
                int dist = q.front().second;
                q.pop();

                if(top == n-1)
                {
                    res = min(res, dist);
                    continue;
                }

                if(!vi[top+1]) vi[top+1] = true, q.push({top+1, dist+1});
                for(int j=0; j<adj[top].size(); ++j)
                    if(!vi[adj[top][j]])
                    {
                        q.push({adj[top][j], dist+1});
                        vi[adj[top][j]] = true;
                    }
            }
            ans[i] = res;
        }
        return ans;
    }
};
