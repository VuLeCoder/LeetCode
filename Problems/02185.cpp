class Solution {
private:
    bool isPrefix(string& word, string& pref)
    {
        if(word.length() < pref.length()) return false;

        for(int i=0; i<pref.length(); ++i)
            if(word[i] != pref[i])
                return false;

        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int ans = 0, l = pref.length();
        for(string& word : words)
            if(isPrefix(word, pref))
                ans++;
        return ans;
    }
};
