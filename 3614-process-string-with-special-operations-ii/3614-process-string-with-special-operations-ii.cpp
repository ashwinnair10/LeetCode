class Solution {
public:
    char processStr(string s, long long k) {
        long long l=0;
        for(auto i:s){
            if(i=='*'){
                l=max(0LL,l-1);
            }
            else if(i=='#'){
                l=2*l;
            }
            else if(i=='%'){

            }
            else{
                l++;
            }
        }
        if(k>=l)
        return '.';
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*'){
                l++;
            }
            else if(s[i]=='#'){
                long long h=l/2;
                if(k>=h)
                k-=h;
                l=h;
            }
            else if(s[i]=='%'){
                k=l-1-k;
            }
            else{
                if(k==l-1)
                return s[i];
                l--;
            }
        }
        return '.';
    }
};