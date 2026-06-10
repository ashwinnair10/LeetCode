class Solution {
public:
    string removeStars(string s) {
        int l=0;
        for(auto i:s){
            if(i=='*'){
                l--;
            }
            else{
                s[l++]=i;
            }
        }
        return s.substr(0,l);
    }
};