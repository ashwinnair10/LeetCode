class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr="";
        for(int i=0;i<s.length();i++){
            if(s[i]>=97&&s[i]<=122)
            curr+=s[i];
            else if(s[i]=='('){
                st.push(curr);
                curr="";
            }
            else if(s[i]==')'){
                reverse(curr.begin(),curr.end());
                curr=st.top()+curr;
                st.pop();
            }
        }
        return curr;
    }
};