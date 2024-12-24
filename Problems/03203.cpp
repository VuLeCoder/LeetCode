class Solution {
private:
    int TreeDiameter(vector<vector<int>>& adj, int u)
    {
        int Max = 0, top;
        queue<int> q;
        int size = adj.size();
        vector<bool> vi(size + 1, false);

        q.push(u); vi[u] = true;
        while(!q.empty())
        {
            int Qsize = q.size();
            for(int i=0; i<Qsize; ++i)
            {
                top = q.front(); q.pop();

                for(int v : adj[top])
                    if(!vi[v]) vi[v] = true, q.push(v);
            }
        }

        for(int i=0; i<=size; ++i) vi[i] = false;

        q.push(top); vi[top] = true;
        while(!q.empty())
        {
            int Qsize = q.size();
            for(int i=0; i<Qsize; ++i)
            {
                top = q.front(); q.pop();

                for(int v : adj[top])
                    if(!vi[v]) vi[v] = true, q.push(v);
            }
            Max++;
        }
        return Max - 1;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        int u, v;

        int n = edges1.size();
        vector<vector<int>> adj1(n + 1, vector<int>(0));
        for(int i=0; i<n; ++i)
        {
            u = edges1[i][0], v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        int diameter1 = TreeDiameter(adj1, 0);
        int res1 = (diameter1 % 2 == 0 ? diameter1/2 : (diameter1 + 1)/2);

        int m = edges2.size();
        vector<vector<int>> adj2(m + 1, vector<int>(0));
        for(int i=0; i<m; ++i)
        {
            u = edges2[i][0], v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int diameter2 = TreeDiameter(adj2, 0);
        int res2 = (diameter2 % 2 == 0 ? diameter2/2 : (diameter2 + 1)/2);

        int ans = max(diameter1, diameter2);
        ans = max(ans, res1 + res2 + 1);
        return ans;
    }
};
