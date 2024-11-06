class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int num : nums)
            sum = (sum + num) % p;
        if(sum == 0) return 0;

        map<long long, int> mod;
        mod[0] = 1;
        long long target = sum;
        long long currSum = 0, needed = 0;
        int min_length = nums.size();
        for(int i=0; i< nums.size(); ++i){
            currSum = (currSum + nums[i]) % p;
            needed = (currSum - target + p) % p;
            mod[currSum] = i + 2;
            if(mod[needed] != 0)
                min_length = min(min_length, i + 2 - mod[needed]);
        }
        return min_length == nums.size() ? -1 : min_length;
    }
};
