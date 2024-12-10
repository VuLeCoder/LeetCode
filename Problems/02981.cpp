class Solution {
public:
    int maximumLength(string s)
    {
        int n = s.length(), ans = 0;
        string str = "";
        str += s[0];

        for(int i=1; i<n; ++i)
        {
            int cnt = 1;
            if(s[i] == s[0])
            {
                cnt++;
                for(int j=i+1; j<n; ++j)
                    if(s[j] == s[0])
                    {
                        cnt++;
                        break;
                    }
            }
            if(cnt == 3) {ans = 1; break;}
        }
        
        int cnt = 1, vt1 = 0;
        for(int i=1; i<n; ++i)
        {
            if(cnt == 3) ans = max(ans, (int)str.length());

            cnt = 1;
            if(s[i] != str.back()) str = "", vt1 = i;
            str += s[i];
            
            int index1 = 0, vt2 = vt1+1;
            string str1 = "";

            for(int j=vt1+1; j<n; ++j)
            {

                str1 += s[j];
                if(str1.back() == str[index1]) index1++;
                else str1 = "", index1 = 0, vt2 = j+1;

                if(index1 == str.length())
                {
                    cnt++;

                    int index2 = 0;
                    string str2 = "";

                    for(int k=vt2+1; k<n; ++k)
                    {
                        str2 += s[k];
                        if(str2.back() == str[index2]) index2++;
                        else str2 = "", index2 = 0;

                        if(index2 == str.length()) {cnt++; break;}
                    }
                }

                if(cnt == 3) break;
            }
        }
        if(ans > 0) return ans;
        return -1;
    }
};
