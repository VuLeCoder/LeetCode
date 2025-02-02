class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        for(int num : arr) mp[num]++;

        for(int num : arr)
            if(num % 2 == 0)
            {
                if(num == 0 && mp[num] > 1) return true;
                if(num !=0 && mp.count(num/2)) return true;
            }
        return false;
    }
};
