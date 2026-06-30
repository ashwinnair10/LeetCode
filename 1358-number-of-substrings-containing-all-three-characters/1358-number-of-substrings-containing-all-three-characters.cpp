class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> a(3,-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]<='c'){
                a[s[i]-'a']=i;
                ans+=min({a[0],a[1],a[2]})+1;
            }
        }
        return ans;
    }
};