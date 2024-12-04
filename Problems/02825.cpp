class Solution {
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        unordered_map<char, char> mp;
        mp['z'] = 'a';
        for(char c = 'a'; c < 'z'; ++c) mp[c] = c+1;

        int j = 0, n = str1.length(), m = str2.length();
        for(int i=0; i<n; ++i)
        {
            if(str2[j] == str1[i] || str2[j] == mp[str1[i]]) j++;
            if(j == m) return true;
        }
        return false;
    }
};
