class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        priority_queue<pair<double, pair<int, int>>> pq;
        for(vector<int>& v : classes)
        {
            double diff = (double)(v[0]+1)/(v[1]+1) - (double)v[0]/v[1];
            pq.push({diff, {v[0], v[1]}});
        }

        while(extraStudents--)
        {
            int passes = pq.top().second.first + 1;
            int total = pq.top().second.second + 1;
            pq.pop();

            double diff = (double)(passes+1)/(total+1) - (double)passes/total;
            pq.push({diff, {passes, total}});
        }

        double ans = 0;
        while(!pq.empty())
        {
            int passes = pq.top().second.first;
            int total = pq.top().second.second;
            pq.pop();

            ans += (double)passes/total;
        }
        return ans/classes.size();
    }
};
