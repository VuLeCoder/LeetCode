class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int Max = quantities[0], Min = 1;
        for(int num : quantities) Max = max(Max, num);

        while(Min < Max)
        {
            int mid = (Min + Max) / 2; // 6
            int cnt = 0;
            for(int num : quantities)
            {
                int tmp = num/mid;
                if(tmp * mid < num) tmp++;

                cnt += tmp;
            }
            if(cnt > n) Min = mid + 1;
            else Max = mid;
        }
        return Min;
    }
};
