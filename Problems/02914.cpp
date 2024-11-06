class Solution {
public:
    int minChanges(string s)
    {
        int ans = 0, n = s.length(), sum = 0;
        for(int i=0; i<n; ++i)
        {
            sum += (s[i] == '1');
            if(i % 2 == 1 && sum % 2 == 1) ans++, sum++;
        }
        return ans;
    }
};
