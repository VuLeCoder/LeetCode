class Solution {
public:
    int maximumSwap(int num) 
    {
        string numStr = to_string(num);
        int n = numStr.size();
        int maxRight[n];
        maxRight[n-1] = n-1;
        for(int i=n-2; i>=0; --i)
            maxRight[i] = numStr[i] > numStr[maxRight[i+1]] ? i : maxRight[i+1];
        
        for(int i=0; i<n; ++i)
            if(numStr[i] < numStr[maxRight[i]])
            {
                swap(numStr[i], numStr[maxRight[i]]);
                return stoi(numStr);
            }
        return num;
    }
};
