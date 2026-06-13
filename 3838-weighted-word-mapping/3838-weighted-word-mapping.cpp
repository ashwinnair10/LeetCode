class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto i:words){
            int s=0;
            for(auto j:i){
                s+=weights[j-'a'];
            }
            s%=26;
            ans+=(char)('z'-s);
        }
        return ans;
    }
};