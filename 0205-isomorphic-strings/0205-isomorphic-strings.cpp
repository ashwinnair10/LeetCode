class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map1(128,-1);
        vector<int> map2(128,-1);
        for(int i=0;i<s.length();i++){
            if(map1[s[i]]!=-1){
                if(map1[s[i]]!=t[i])
                return false;
            }
            else{
                if(map2[t[i]]!=-1)
                return false;
                map1[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
        }
        return true;
    }
};