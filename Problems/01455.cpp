class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int j = 0, index = 1, n = sentence.length();
        int i = 0;
        while(i < n)
        {
            if(searchWord[j] == sentence[i]) j++;
            else
            {
                j = 0;
                while(i < n && sentence[i] != ' ') i++;
                index++;
            }
            
            if(j == searchWord.length()) return index;
            i++;
        }
        return -1;
    }
};
