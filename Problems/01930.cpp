class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        vector<int> left(26, -1), right(26, -1);

        for(int i=0; i<n; ++i)
            if(left[s[i] - 'a'] == -1)
                left[s[i] - 'a'] = i;

        for(int i=n-1; i>=0; --i)
            if(right[s[i] - 'a'] == -1)
                right[s[i] - 'a'] = i;

        long long ans = 0;
        vector<bool> between(26, false);
        for(int c=0; c<26; ++c)
        {
            for(int i=0; i<26; ++i) between[i] = false;
            for(int i=left[c]+1; i<right[c]; ++i)
                if(!between[s[i] - 'a'])
                {
                    between[s[i] - 'a'] = true;
                    ans++;
                }
        }
        return ans;
    }
};
