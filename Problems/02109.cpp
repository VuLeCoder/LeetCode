class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        string ans = "";
        int index = 0, n = spaces.size(), l = s.length();

        for(int i=0; i<l; ++i)
        {
            if(index < n && i == spaces[index]) ans += ' ', index++;
            ans += s[i];
        }
        return ans;
    }
};
