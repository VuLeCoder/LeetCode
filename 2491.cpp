class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size();
        long long sum = 0;
        map<int, int> mp;
        for(int num : skill){
            sum += num;
            mp[num]++;
        }
        if(sum*2 % n != 0) return -1;

        sum = sum*2 / n;
        long long ans = 0;
        for(int i=0; i< n; ++i)
            if(mp[skill[i]] == mp[sum - skill[i]])
            {
                if(mp[skill[i]] > 0)
                {
                    ans += skill[i] * (sum - skill[i]);
                    mp[skill[i]]--, mp[sum - skill[i]]--;
                }
            }
            else return -1;
        return ans;
    }
};

/*
class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int total_skill = skill[0] + skill[n-1];
        long long ans = (long long)skill[0] * skill[n-1];
        for(int i=1; i<n/2; ++i)
            if(skill[i] + skill[n-1-i] == total_skill)
                ans += (long long)skill[i] * skill[n-1-i];
            else return -1;
        return ans;
    }
};
*/
