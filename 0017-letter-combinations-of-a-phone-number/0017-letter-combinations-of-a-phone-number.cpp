class Solution {
public:
    vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string& d,int ind,string s,vector<string>& ans){
        if(ind==d.length()){
            ans.push_back(s);
            return;
        }
        for(auto i:map[d[ind]-48]){
            dfs(d,ind+1,s+i,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs(digits,0,"",ans);        
        return ans;
    }
};