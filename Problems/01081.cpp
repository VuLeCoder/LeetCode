class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> append(26, false);
        vector<int> cnt(26, 0);
        for(char c : s) {
            append[c - 'a'] = true;
            cnt[c - 'a'] += 1;
        }

        stack<char> st;
        for(int i=0; i<s.length(); ++i) {
            
            if(st.empty()) {
                st.push(s[i]);
                append[s[i] - 'a'] = false;
                cnt[s[i] - 'a'] -= 1;
                continue;
            }

            if(!append[s[i] - 'a']) {
                cnt[s[i] - 'a'] -= 1;
                continue;
            }

            while(!st.empty()) {
                if(cnt[st.top() - 'a'] == 0) break;
                if(st.top() < s[i]) break;

                append[st.top() - 'a'] = true;
                st.pop();
            }

            st.push(s[i]);
            append[s[i] - 'a'] = false;
            cnt[s[i] - 'a'] -= 1;
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
