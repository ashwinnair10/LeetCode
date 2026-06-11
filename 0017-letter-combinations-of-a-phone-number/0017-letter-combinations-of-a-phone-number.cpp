class Solution {
public:
    void dfs(string& d,int ind,string s,vector<string>& ans){
        if(ind==d.length()){
            ans.push_back(s);
            return;
        }
        if(d[ind]=='2'){
            dfs(d,ind+1,s+'a',ans);
            dfs(d,ind+1,s+'b',ans);
            dfs(d,ind+1,s+'c',ans);
        }
        if(d[ind]=='3'){
            dfs(d,ind+1,s+'d',ans);
            dfs(d,ind+1,s+'e',ans);
            dfs(d,ind+1,s+'f',ans);
        }
        if(d[ind]=='4'){
            dfs(d,ind+1,s+'g',ans);
            dfs(d,ind+1,s+'h',ans);
            dfs(d,ind+1,s+'i',ans);
        }
        if(d[ind]=='5'){
            dfs(d,ind+1,s+'j',ans);
            dfs(d,ind+1,s+'k',ans);
            dfs(d,ind+1,s+'l',ans);
        }
        if(d[ind]=='6'){
            dfs(d,ind+1,s+'m',ans);
            dfs(d,ind+1,s+'n',ans);
            dfs(d,ind+1,s+'o',ans);
        }
        if(d[ind]=='7'){
            dfs(d,ind+1,s+'p',ans);
            dfs(d,ind+1,s+'q',ans);
            dfs(d,ind+1,s+'r',ans);
            dfs(d,ind+1,s+'s',ans);
        }
        if(d[ind]=='8'){
            dfs(d,ind+1,s+'t',ans);
            dfs(d,ind+1,s+'u',ans);
            dfs(d,ind+1,s+'v',ans);
        }
        if(d[ind]=='9'){
            dfs(d,ind+1,s+'w',ans);
            dfs(d,ind+1,s+'x',ans);
            dfs(d,ind+1,s+'y',ans);
            dfs(d,ind+1,s+'z',ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs(digits,0,"",ans);        
        return ans;
    }
};