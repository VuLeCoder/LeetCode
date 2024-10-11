class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int arrival = times[targetFriend][0];
        sort(times.begin(), times.end());
        int chair[10001];
        memset(chair, 0, sizeof(chair));

        int i = 0;
        while(times[i][0] <= arrival)
        {
            int c = 0;
            while(chair[c] > times[i][0]) c++;

            if(times[i][0] == arrival) return c;

            chair[c] = times[i][1];
            i++;
        }
        return 0;
    }
};
