class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(haystack.length() < needle.length()) return -1;

        deque<char> n, w;
        for(char c : needle) n.push_back(c);

        int k = needle.length(), l = haystack.length();
        for(int i=0; i<k; ++i) w.push_back(haystack[i]);
        if(w == n) return 0;
        for(int i=0; i<l-k; ++i)
        {
            w.pop_front();
            w.push_back(haystack[i+k]);
            if(w == n) return i+1;
        }
        return -1;
    }
};
