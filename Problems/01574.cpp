class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int i = 0, n = arr.size();
        while(i < n-1 && arr[i] <= arr[i+1]) i++;

        int j = arr.size()-1;
        int ans = j-i;
        while(i < j && (j == arr.size()-1 || arr[j] <= arr[j+1]))
        {
            while(i >= 0 && arr[i] > arr[j]) i--;
            ans = min(ans, j - i - 1);
            j--;
        }
        return ans;
    }
};
