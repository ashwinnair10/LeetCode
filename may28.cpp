class Solution {
public:
    int equalSubstring(string s, string t, int mc) {
        int ind=0,l=0,sum=0,m=0;
        for(int i=0;i<s.length();i++){
            if(sum+abs(s[i]-t[i])<=mc){
                sum+=abs(s[i]-t[i]);;
                l++;
                m=max(m,l);
            }
            else{
                sum-=abs(s[ind]-t[ind]);
                sum+=abs(s[i]-t[i]);
                ind++;
            }
        }
        return m;
    }
};