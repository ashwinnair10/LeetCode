class Solution {
public:
    int longestValidParentheses(string s) {
        int m=INT_MIN;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.size())
                st.push(i);
                m=max(m,i-st.top());
            }
        }
        return max(m,0);
    }
};