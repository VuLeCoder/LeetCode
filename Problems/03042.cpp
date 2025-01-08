class Solution {
private:
    bool checkPreAndSuf(string& s1, string& s2)
    {
        if(s1.length() > s2.length()) return false;
        
        bool check = true;
        for(int i=0; i<s1.length(); ++i)
            if(s1[i] != s2[i])
            {
                check = false;
                break;
            }
        
        if(check)
        {
            int i = s1.length(), j = s2.length() - 1;
            while(i--)
            {
                if(s1[i] != s2[j])
                {
                    check = false;
                    break;
                }
                j--;
            }
        }
        return check;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words)
    {
        int ans = 0, n = words.size();
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
                ans += checkPreAndSuf(words[i], words[j]);
        return ans;
    }
};
