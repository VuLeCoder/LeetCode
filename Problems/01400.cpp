class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        if(s.length() == k) return true;

        vector<int> letter(26, 0);
        for(char c : s) letter[c - 'a']++;

        int cnt = 0;
        for(int i=0; i<26; ++i) cnt += (letter[i] % 2 != 0);

        if(cnt <= k) return true;
        return false;
    }
};
