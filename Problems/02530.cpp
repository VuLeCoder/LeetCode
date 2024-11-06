class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        long long ans = 0;
        while(k--){
            int score = pq.top();
            pq.pop();
            ans += score;
            pq.push(ceil(score/3.0));
        }
        return ans;
    }
};
