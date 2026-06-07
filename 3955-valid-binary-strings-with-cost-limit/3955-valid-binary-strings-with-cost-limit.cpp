class Solution {
public:
    void test(vector<string>& ans,int& n,int& k,string s,int cost){
        if(s.length()==n){
            if(cost<=k)
                ans.push_back(s);
            return;
        }
        if(s[s.length()-1]=='0'){
            test(ans,n,k,s+"0",cost);
            test(ans,n,k,s+"1",cost+s.length());
        }
        else{
            test(ans,n,k,s+"0",cost);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string s="";
        vector<string> ans;
        test(ans,n,k,s+"0",0);
        test(ans,n,k,s+"1",0);
        return ans;
    }
};