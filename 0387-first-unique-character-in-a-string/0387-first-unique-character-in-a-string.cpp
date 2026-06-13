class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> a(26,-1);       
        for(int i=0;i<s.length();i++){
            if(a[s[i]-'a']==-1){
                a[s[i]-'a']=i;
            }
            else if(a[s[i]-'a']<INT_MAX){
                a[s[i]-'a']=INT_MAX;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            if(a[i]!=-1){
                ans=min(ans,a[i]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};