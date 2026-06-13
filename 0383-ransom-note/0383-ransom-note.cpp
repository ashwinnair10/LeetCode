class Solution {
public:
    bool canConstruct(string x, string y) {
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<x.length();i++)
        a[x[i]-'a']++;
        for(int i=0;i<y.length();i++)
        b[y[i]-'a']++;
        for(int i=0;i<26;i++)
        if(a[i]>b[i])
        return false;
        return true;
    }
};