class Solution {
public:
    void test(vector<string>& ans,string s,int open,int closed,int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            test(ans,s+'(',open+1,closed,n);
        }
        if(closed<open){
            test(ans,s+')',open,closed+1,n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        test(ans,s,0,0,n);
        return ans;
    }
};