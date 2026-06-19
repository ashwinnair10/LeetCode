class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> r(3);
        string s1="qwertyuiopQWERTYUIOP",s2="asdfghjklASDFGHJKL",s3="zxcvbnmZXCVBNM";
        for(auto i:s1)
        r[0].insert(i);
        for(auto i:s2)
        r[1].insert(i);
        for(auto i:s3)
        r[2].insert(i);
        vector<string> ans;
        for(auto i:words){
            int p=-1;
            bool f=true;
            for(auto j:i){
                if(p==-1){
                    for(int k=0;k<3;k++)
                    if(r[k].find(j)!=r[k].end()){
                        p=k;
                        break;
                    }
                }
                else{
                    if(r[p].find(j)==r[p].end()){
                        f=false;
                        break;
                    }
                }
            }
            if(f)
            ans.push_back(i);
        }
        return ans;
    }
};