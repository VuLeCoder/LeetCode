class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int cnt[26] = {0};
        for(char c : s) cnt[c - 'a']++;

        priority_queue<pair<char, int>> pq;
        for(int i=0; i<26; ++i)
            if(cnt[i] > 0)
                pq.push({'a'+i, cnt[i]});
        
        string ans = "";
        while(!pq.empty())
        {
            char c = pq.top().first;
            int repeat = pq.top().second;
            pq.pop();

            int Min = min(repeat, repeatLimit);
            repeat -= Min;

            while(Min--) ans += c;
            
            if(repeat > 0 && !pq.empty())
            {
                pair<char, int> p = pq.top(); pq.pop();
                ans += p.first; p.second--;

                pq.push({c, repeat});
                if(p.second > 0) pq.push(p);
            }
        }
        return ans;
    }
};
