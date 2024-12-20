class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        priority_queue<int> pq;
        for(int gift : gifts) pq.push(gift);

        while(k--)
        {
            int tmp = sqrt(pq.top());
            pq.pop(), pq.push(tmp);
        }

        long long ans = 0;
        while(!pq.empty()) ans += pq.top(), pq.pop();
        return ans;
    }
};
