class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<int> letter(26, 0), tmp(26, 0);
        for(string& word : words2)
        {
            for(char c : word) tmp[c - 'a']++;

            for(int i=0; i<26; ++i)
            {
                letter[i] = max(letter[i], tmp[i]);
                tmp[i] = 0;
            }
        }
        
        vector<string> ans;
        for(string& word : words1)
        {
            vector<int> check(26, 0);
            for(char c : word) check[c - 'a']++;

            bool isSuperset = true;
            for(int i=0; i<26; ++i)
                if(check[i] < letter[i])
                {
                    isSuperset = false;
                    break;
                }
            if(isSuperset) ans.push_back(word);
        }
        return ans;
    }
};
