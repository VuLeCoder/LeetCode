class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit)
    {
        int n = nums.size();
        vector<pair<int, int>> sortedArray(n);
        for(int i=0; i<n; ++i)
        {
            sortedArray[i].first = nums[i];
            sortedArray[i].second = i;
        }
        sort(sortedArray.begin(), sortedArray.end());

        vector<int> ans(n);
        vector<int> tmp(1, sortedArray[0].second);
        int start = 0, k = 0;
        for(int i=1; i<n; ++i)
        {
            if(abs(sortedArray[i].first - sortedArray[i-1].first) <= limit)
                tmp.push_back(sortedArray[i].second);

            else
            {
                sort(tmp.begin(), tmp.end());
                k = 0;
                for(int j=start; j<i; ++j)
                    ans[tmp[k++]] = sortedArray[j].first;
                
                start = i;
                tmp.clear();
                tmp.push_back(sortedArray[start].second);
            }
        }
        sort(tmp.begin(), tmp.end());
        k = 0;
        for(int i=start; i<n; ++i) ans[tmp[k++]] = sortedArray[i].first;
        return ans;
    }
};
