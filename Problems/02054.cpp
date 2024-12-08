class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        unordered_map<int, int> mp;
        int n = events.size();
        for(int i=0; i<n; ++i)
        {
            if(!mp.count(events[i][0])) mp[events[i][0]] = events[i][2];
            else mp[events[i][0]] = max(mp[events[i][0]], events[i][2]);
        }

        vector<pair<int, int>> a;
        for(auto &it : mp) a.push_back({it.first, it.second});
        sort(a.begin(), a.end());

        int m = a.size()-1;
        for(int i=m-1; i>=0; --i) a[i].second = max(a[i].second, a[i+1].second);

        int ans = 0;
        sort(events.begin(), events.end());
        for(int i=0; i<n; ++i)
        {
            int res = events[i][2], s = events[i][1] + 1;
            
            auto it = lower_bound(a.begin(), a.end(), make_pair(s, 0));
            if(it != a.end()) res += it->second;
            ans = max(ans, res);
        }
        return ans;
    }
};
