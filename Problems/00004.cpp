class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.size(), m = nums2.size();
        int left = 0, right = n;
        while(left <= right)
        {
            int i = (left+right)/2;
            int j = (n+m+1)/2 - i;

            int max_left1 = (i == 0) ? INT_MIN : nums1[i-1];
            int min_right1 = (i == n) ? INT_MAX : nums1[i];
            int max_left2 = (j == 0) ? INT_MIN : nums2[j-1];
            int min_right2 = (j == m) ? INT_MAX : nums2[j];

            if(max_left1 <= min_right2 && max_left2 <= min_right1)
                if((m+n) % 2 == 0)
                    return (max(max_left1, max_left2) + min(min_right1, min_right2))/2.0;
                else
                    return max(max_left1, max_left2);
            else if(max_left1 > min_right2)
                right = i - 1;
            else
                left = i + 1;
        }
        return 0;
    }
};
