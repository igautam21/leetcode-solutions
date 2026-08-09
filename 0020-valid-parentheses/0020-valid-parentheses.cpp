class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(s[i]);
            else if((st.top()=='('||st.top()=='{'||st.top()=='[')&&(s[i]=='('||s[i]=='{'||s[i]=='[')){
                st.push(s[i]);
            }
            else if(st.top()=='(' && s[i]==')') st.pop();
            else if(st.top()=='{' && s[i]=='}') st.pop();
            else if(st.top()=='[' && s[i]==']') st.pop();
            else return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};