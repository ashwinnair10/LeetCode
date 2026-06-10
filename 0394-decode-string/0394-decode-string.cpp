class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> st;
        string num="",str="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                count.push(stoi(num));
                st.push(str);
                num="";
                str="";
            }
            else if(s[i]==']'){
                int c=count.top();
                count.pop();
                string k="";
                while(c>0){
                    k+=str;
                    c--;
                }
                if(!st.empty())
                str=st.top()+k;
                st.pop();
            }
            else if(s[i]>=97&&s[i]<=122){
                str+=s[i];
            }
            else{
                num+=s[i];
            }
        }
        return str;
    }
};