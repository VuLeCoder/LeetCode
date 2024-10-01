class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder(k, 0);

        for(int num : arr)
            remainder[(num % k + k) % k]++;

        if(remainder[0] % 2 != 0) return false;
        for(int i=1; i<=k/2; ++i)
            if(remainder[i] != remainder[k-i])
                return false;
        if(k % 2 == 0)
            if(remainder[k/2] % 2 != 0)
                return false;
        return true;
    }
};
