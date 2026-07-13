class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        long num, curr;

        for(int i=1; i<=9; ++i) {
            num = 0, curr = i;
            while(curr < 10) {
                num = num * 10 + curr++;
                if(num > high) break;

                if(num >= low) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
