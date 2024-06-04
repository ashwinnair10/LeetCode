class Solution {
public:
    int longestPalindrome(string s) {
        int m=INT_MIN,ind=0;
        vector<int> hash(52,0);
        for(int i=0;i<s.length();i++){
            if(s[i]>=65&&s[i]<=90){
                hash[26+s[i]-65]++;
            }
            else{
                hash[s[i]-97]++;
            }
        }
        for(int i=0;i<52;i++){
            if(hash[i]%2){
                if(m<hash[i])
                ind=i;
                m=max(m,hash[i]);
            }
        }
        cout<<ind<<'\n';
        int c=0;
        for(int i=0;i<52;i++){
            if(i!=ind)
            c+=(hash[i]/2)*2;
        }
        c+=hash[ind];
        return c;
    }
};