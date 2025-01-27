class Solution {
private:
    int n;
    vector<vector<bool>> courses;
    vector<int> check;
    void add(vector<vector<int>>& graph, int u)
    {
        queue<int> q;
        for(int i=0; i<n; ++i) check[i] = false;
        for(int v : graph[u]) q.push(v), check[v] = true;
        
        int x;
        while(!q.empty())
        {
            x = q.front();
            q.pop();

            courses[u][x] = true;
            for(int v : graph[x])
                if(!check[v])
                    q.push(v), check[v] = true;
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        n = numCourses;
        vector<vector<int>> graph(numCourses);
        for(vector<int>& v : prerequisites) graph[v[0]].push_back(v[1]);
        
        check.resize(numCourses);
        courses.resize(numCourses, vector<bool>(numCourses, false));
        for(int i=0; i<numCourses; ++i) add(graph, i);

        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); ++i)
            ans[i] = courses[queries[i][0]][queries[i][1]];
        return ans;
    }
};
