class Solution {
private:
    int Max = 1;

public:
    void check(const vector<bool>& arr, const string& s) {
        unordered_map<string, bool> mp;
        string str = ""; 
        bool isValid = true;

        for (int i = 0; i < arr.size(); ++i) {
            str += s[i];
            if (arr[i]) {
                if (mp[str]) {
                    isValid = false;
                    break;
                }
                mp[str] = true;
                str.clear();
            }
        }

        str += s[arr.size()];
        if (mp[str]) isValid = false;
        mp[str] = true;

        if (isValid) {
            Max = max(Max, static_cast<int>(mp.size()));
        }
    }

    void solve(const string& s, vector<bool>& arr, int index) {
        if (index == s.length() - 1) {
            check(arr, s);
            return;
        }
        
        arr[index] = true;
        solve(s, arr, index + 1);

        arr[index] = false;
        solve(s, arr, index + 1);
    }

    int maxUniqueSplit(string s) {
        int n = s.length() - 1;
        vector<bool> arr(n, false);
        solve(s, arr, 0);
        return Max;
    }
};
