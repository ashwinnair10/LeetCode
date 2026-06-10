class Solution {
public:
    bool closeStrings(string a, string b) {
        if(a.length()!=b.length())
        return false;
        vector<int> f1(26,0),f2(26,0);
        for(int i=0;i<a.length();i++){
            f1[a[i]-97]++;
            f2[b[i]-97]++;
        }
        for(int i=0;i<26;i++){
            if((f1[i]&&!f2[i])||(!f1[i]&&f2[i]))
            return false;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i])
            return false;
        }
        return true;
    }
};