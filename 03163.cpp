class Solution {
public:
    string compressedString(string word) {
        int n = word.length(), cnt = 1;
        string ans = "";
        for(int i=1; i<n; ++i)
            if(word[i] == word[i-1])
            {
                cnt++;
                if(cnt > 9) ans += (cnt-1 +'0'), ans += word[i], cnt = 1;
            }
            else
            {
                ans += (cnt +'0'), ans += word[i-1];
                cnt = 1;
            }
        ans += (cnt +'0'), ans += word[n-1];
        return ans;
    }
};
