class Solution {
public:
    string removeOccurrences(string s, string part)
    {
        bool kt;
        string tmp = "";
        for(int i=0; i<s.length(); ++i)
        {
            kt = true;
            for(int j=0; j<part.length(); ++j)
                if(j + i >= s.length() || s[j + i] != part[j])
                {
                    kt = false;
                    break;
                }
            if(kt)
            {
                i += part.length();
                while(i < s.length()) tmp += s[i++];
                return removeOccurrences(tmp, part);
            }
            else tmp += s[i];
        }
        return s;
    }
};
