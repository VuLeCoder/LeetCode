class Solution {
public:
    string clearDigits(string s)
    {
        string ans = "";
        for(char c : s)
            if(c <= '9' && c >= '0')
            {
                if(ans.length() > 0) ans.pop_back();
                else ans += c;
            }
            else ans += c;
        return ans;
    }
};
