class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-97]--;
            v[t[i]-97]++;
        }
        v[t[t.length()-1]-97]++;
        for(int i=0;i<26;i++){
            if(v[i])
            return (char)(i+97);
        }
        return '\0';
    }
};