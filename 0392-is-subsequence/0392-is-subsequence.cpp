class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        for(auto i:t){
            if(s[l]==i){
                l++;
            }
        }
        return l==s.length();
    }
};