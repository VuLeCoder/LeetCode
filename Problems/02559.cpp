class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        vector<int> preFix(words.size(), 0);
        if(isVowel(words[0][0]) && isVowel(words[0].back())) preFix[0] = 1;
        for(int i=1; i<words.size(); ++i)
        {
            preFix[i] = preFix[i-1];
            if(isVowel(words[i][0]) && isVowel(words[i].back())) preFix[i] += 1;
        }

        int n = queries.size();
        vector<int> ans(n);
        for(int i=0; i<n; ++i) ans[i] = preFix[queries[i][1]] - preFix[queries[i][0]] + (isVowel(words[queries[i][0]][0]) && isVowel(words[queries[i][0]].back()));
        return ans;
    }
};
