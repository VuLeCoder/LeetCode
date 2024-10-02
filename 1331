class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        if(arr.empty()) return arr;

        unordered_map<int,int> rank;
        vector<int> copy_arr(arr);
        sort(copy_arr.begin(), copy_arr.end());
        
        int pre_num = copy_arr[0], i = 1;
        for(int num : copy_arr){
            if(num > pre_num) i++;
            rank[num] = i;
            pre_num = num;
        }
        for(int i=0; i<arr.size(); ++i)
            arr[i] = rank[arr[i]];
        return arr;
    }
};
