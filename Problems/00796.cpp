class Solution {
public:
    bool rotateString(string s, string goal)
    {
        if(s.length() != goal.length()) return false;

        s += s;
        int j = 0;
        for(int i=0; i<s.length()-goal.length(); ++i)
        {
            int j=0;
            while(j <  goal.length() && goal[j] == s[i+j]) j++;
            if(j == goal.length()) return true;
        }
        return false;
    }
};
