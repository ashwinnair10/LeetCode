class Solution {
public:
    string mergeAlternately(string a, string b) {
        int i=0,j=0,m=a.length(),n=b.length();
        string ans="";
        while(i<m&&j<n){
            ans+=a[i++];
            ans+=b[j++];
        }
        while(i<m)
        ans+=a[i++];
        while(j<n)
        ans+=b[j++];
        return ans;
    }
};