class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> left, right;
        int n = boxes.length(), sumL = 0, sumR = 0;
        for(int i=0; i<n; ++i)
            if(boxes[i] == '1')
            {
                right.push_back(i);
                sumR++;
            }
        
        vector<int> ans(n, 0);
        for(int i=0; i<n; ++i)
        {
            if(boxes[i] == '1') right.pop_back(), sumR--;
            ans[i] = sumL + sumR;

            if(boxes[i] == '1') left.push_back(i), sumL++;
            sumL += left.size(), sumR -= right.size();
        }
        return ans;
    }
};
