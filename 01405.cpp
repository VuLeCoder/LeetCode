class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        string ans = "";
        int cur_a = 0, cur_b = 0, cur_c = 0;
        int n = a+b+c;
        for(int i=0; i<n; ++i)
        {
            if(a>0 && (a>=b && a>=c && cur_a < 2 || cur_b == 2 || cur_c == 2))
            {
                ans += 'a';
                cur_a++; a--;
                cur_b = cur_c = 0;
            }
            else if(b>0 && (b>=a && b>=c && cur_b < 2 || cur_a == 2 || cur_c == 2))
            {
                ans += 'b';
                cur_b++; b--;
                cur_a = cur_c = 0;
            }
            else if(c>0 && (c>=b && c>=a && cur_c < 2 || cur_a == 2 || cur_b == 2))
            {
                ans += 'c';
                cur_c++; c--;
                cur_a = cur_b = 0;
            }
            else break;
        }
        return ans;
    }
};
