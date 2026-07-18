class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNum = nums[0], minNum = nums[0];
        for(int num : nums) {
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
        return __gcd(maxNum, minNum);
    }
};
