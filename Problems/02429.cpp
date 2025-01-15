class Solution {
private:
    string toBit(int n)
    {
        string ans = "";
        while(n)
        {
            ans += (n % 2 + '0');
            n /= 2;
        }

        return ans;
    }

    int cntBit_1(string str)
    {
        int cnt = 0;
        for(int i=0; i<str.length(); ++i)
            cnt += (str[i] == '1');
        return cnt;
    }

    int bitToInt(string str)
    {
        int ans = 0;
        for(int i=0; i<str.length(); ++i)
            ans += pow(2, i) * (str[i] - '0');
        return ans;
    }

public:
    int minimizeXor(int num1, int num2)
    {
        string str = toBit(num1);
        int n1 = cntBit_1(str), n2 = cntBit_1(toBit(num2));

        if(n2 > n1)
        {
            int diff = n2 - n1;
            for(int i=0; i<str.length(); ++i)
            {
                if(str[i] == '0') str[i] = '1', diff--;
                if(diff == 0) break;
            }

            while(diff--) str += '1';
        }
        else if(n1 > n2)
        {
            int diff = n1 - n2;
            for(int i=0; i<str.length(); ++i)
            {
                if(str[i] == '1') str[i] = '0', diff--;
                if(diff == 0) break;
            }
        }

        return bitToInt(str);
    }
};
