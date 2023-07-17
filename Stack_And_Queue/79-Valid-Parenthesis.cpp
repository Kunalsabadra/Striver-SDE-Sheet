bool isValidParenthesis(string s)
{
    int n = s.length();
    stack<char>st;
    for(int i=0; i<n; i++){
        if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
            st.push(s[i]);
        } else {
          if (st.empty())
            return false;
          char c = s[i];
          char ch = st.top();
          if ((c == ')' and ch == '(') or (c == ']' and ch == '[') or
              (c == '}' and ch == '{')) st.pop();

              else return false;
        }
    }

    if(st.empty()) return true;
    else return false;
}
