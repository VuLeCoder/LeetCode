class Solution {
public:
    int minLength(string s) 
    {
        stack<char> tmp;
        for(char c : s)
            if(tmp.empty()) tmp.push(c);
            else
            {
                if(c == 'B' && tmp.top() == 'A')
                    tmp.pop();
                else if(c == 'D' && tmp.top() == 'C')
                    tmp.pop();
                else tmp.push(c);
            }
        return tmp.size();
    }
};
