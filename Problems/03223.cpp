class Solution {
public:
    int minimumLength(string s)
    {
        vector<int> letter(26, 0);
        for(char c : s) letter[c - 'a']++;

        int ans = 0;
        for(int i=0; i<26; ++i)
        {
            while(letter[i] > 2) letter[i] -= 2;
            ans += letter[i];
        }
        return ans;
    }
};
