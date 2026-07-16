class Solution {
private:
    vector<int> constuctPrefixGcd(const vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxNum = nums[0];

        for(int i=0; i<n; ++i) {
            maxNum = max(maxNum, nums[i]);
            prefixGcd[i] = __gcd(maxNum, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        return prefixGcd;
    }
    
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd = constuctPrefixGcd(nums);
        
        int n = prefixGcd.size();
        long long ans = 0;
        for(int i=0; i<n/2; ++i) {
            if(i == n - 1 - i) break;
            ans += __gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }
        return ans;
    }
};
