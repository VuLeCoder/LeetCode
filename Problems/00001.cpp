class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;++i) mp[nums[i]]=i+1;
        
        for(int i=0;i<n;++i)
            if(mp[target-nums[i]]!=0)
                if(mp[target-nums[i]]!=i+1)
                    return {i,mp[target-nums[i]]-1};
        return {};
    }
};
