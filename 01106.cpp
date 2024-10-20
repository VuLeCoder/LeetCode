class Solution {
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st1, st2;
        for(char c : expression)
        {
            if(c == ',') continue;
            if(c == 'f' || c == 't') st2.push(c);
            if(c == '(') st1.push(c), st2.push(c);
            if(c == '!' || c == '|' || c == '&') st1.push(c);
            if(c == ')')
            {
                char x = st2.top();
                bool ans = (x == 'f' ? 0 : 1);

                st1.pop();
                x = st1.top();
                st1.pop();

                while(st2.top() != '(')
                {
                    st2.pop();
                    if(x == '!') ans = !ans;
                    if(st2.top() == '(') break;
                    if(x == '|') ans |= (st2.top() == 'f' ? 0 : 1);
                    if(x == '&') ans &= (st2.top() == 'f' ? 0 : 1);
                }
                st2.pop();
                c = (ans == 1 ? 't' : 'f');
                st2.push(c);
            }
        }
        return st2.top() == 'f' ? false : true; 
    }
};
