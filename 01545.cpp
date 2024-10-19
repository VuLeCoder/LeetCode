class Solution {
public:
    char findKthBit(int n, int k) 
    {
        int cnt_invert = 0;
        int len = (1 << n) - 1;
        while(k > 1)
        {
            if(k == len/2 + 1) 
                return cnt_invert % 2 == 0 ? '1' : '0';
            
            if(k > len/2){
                k = len - k + 1;
                cnt_invert++;
            }
            len /= 2;
        }
        return cnt_invert % 2 == 0 ? '0' : '1';
    }
};
