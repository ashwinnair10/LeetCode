class Solution {
public:
    unordered_map<string,bool> map;
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) 
        return false;
        if(s1==s2)
        return true;
        if(s1.size()==1)
        return false;
        
        int n=s1.size();
        if(map.find(s1+"-"+s2)!=map.end())
        return map[s1+"-"+s2];

        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))
            return true;
            if(isScramble(s1.substr(0,i),s2.substr(n-i))&&isScramble(s1.substr(i),s2.substr(0,n-i)))
            return true;
        }
        map[s1+"-"+s2]=false;
        return false;
    }
};