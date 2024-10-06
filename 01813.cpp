class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        deque<string> s1, s2;
        string tmp = "";
        for(char c : sentence1)
            if(c == ' '){
                s1.push_back(tmp);
                tmp = "";
            }
            else tmp += c;
        s1.push_back(tmp);

        tmp = "";
        for(char c : sentence2)
            if(c == ' '){
                s2.push_back(tmp);
                tmp = "";
            }
            else tmp += c;
        s2.push_back(tmp);

        bool check = true;
        while(check)
        {
            check = false;
            if(s1.size() && s2.size() && s1.back() == s2.back())
                s1.pop_back(), s2.pop_back(), check = true;
            if(s1.size() && s2.size() && s1.front() == s2.front())
                s1.pop_front(), s2.pop_front(), check = true;

            if(s1.empty() || s2.empty()) return true;
        }
        return false;
    }
};
