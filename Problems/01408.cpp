class Solution {
public:
    vector<string> stringMatching(vector<string>& words)
    {
        vector<bool> check(words.size(), false);
        for(int i=0; i<words.size(); ++i)
            for(int j=0; j<words.size(); ++j)
            {
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos)
                {
                    check[i] = true;
                    break;
                }
            }
        
        vector<string> ans;
        for(int i=0; i<words.size(); ++i)
            if(check[i])
                ans.push_back(words[i]);
        return ans;
    }
};
