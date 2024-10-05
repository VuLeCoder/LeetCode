class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int> permutation;
        for(char c : s1) permutation[c]++;
        
        int n = s2.length(), l = s1.length();
        int i=0, pre_i;
        bool check = false;
        while(i < n)
        {
            if(l == 0) return true;
            if(permutation[s2[i]] > 0)
            {
                if(!check) pre_i = i, check = true;
                permutation[s2[i]]--, l--;
            }
            else if(check)
            {
                check = false;
                for(int j=pre_i; j<i; ++j)
                {
                    if(permutation[s2[i]] > 0){
                        permutation[s2[i]]--,l--;
                        check = true;
                        pre_i = j;
                        break;
                    }
                    permutation[s2[j]]++,l++;
                }
            }
            i++;
        }
        if(l == 0) return true;
        return false;
    }
};
