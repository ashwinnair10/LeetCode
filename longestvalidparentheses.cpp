class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int m=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            stack.push(i);
            else{
                stack.pop();
                if(!stack.size()){
                    stack.push(i);
                }
                else{
                    m=max(m,i-stack.top());
                }
            }
        }
        return m;
    }
};