class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        path+='/';
        string s="";
        cout<<path<<' '<<path.length()<<'\n';
        for(int i=0;i<path.length();i++){
            cout<<i<<' ';
            if(path[i]=='/'){
                if(s==".."){
                    if(!stack.empty())
                    stack.pop();
                }
                else if(s=="."){
                }
                else if(s!=""){
                    stack.push(s);
                }
                s="";
            }
            else{
                s+=path[i];
            }
            cout<<i<<' ';
        }
        string ans="";
        while(!stack.empty()){
            ans='/'+stack.top()+ans;
            stack.pop();
        }
        if(ans=="")
        return "/";
        return ans;
    }
};