class Solution {
public:
    int minSwaps(string s) 
    {
        int i=0, j = s.length() - 1;
        int close = 0, open = 0;
        int ans = 0;
        while(i < s.length())
        {
            if(s[i] == '[') open++;
            if(s[i] == ']') close++;

            if(close > open)
            {
                while(j > i){
                    if(s[j] == '[') break;
                    j--;
                }
                s[i] = '[';
                s[j] = ']';
                close--;
                open++;
                ans++;
            }
            i++;
        }
        return ans;
    }
};
