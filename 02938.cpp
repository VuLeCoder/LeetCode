class Solution {
public:
    long long minimumSteps(string s) 
    {
        int n = s.length(), black_ball = 0;
        for(char c : s)
            if(c == '1') 
                black_ball++;
      
        int j = n - black_ball;
        long long ans = 0;
        for(int i=0; i<n; ++i)
        {
            if(j == n) break;
            if(s[i] == '1') ans += (j - i), j++;
        }
        return ans;
    }
};
