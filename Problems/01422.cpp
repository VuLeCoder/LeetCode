class Solution {
public:
    int maxScore(string s)
    {
        int ans = 0;
        int scoreL = 0, scoreR = 0;
        for(char c : s) scoreR += (c == '1');

        for(int i=0; i<s.length()-1; ++i)
        {
            if(s[i] == '0') scoreL++;
            else scoreR--;
            ans = max(ans, scoreL + scoreR);
        }
        return ans;
    }
};
