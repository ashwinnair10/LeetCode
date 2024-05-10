class Solution {
public:
    int pal(string s){
        string rev=s;
        int n=rev.length();
        for(int i=0;i<n/2;i++){
            swap(rev[i],rev[n-i-1]);
        }
        if(rev==s)
        return 1;
        return 0;
    }
    string longestPalindrome(string s) {
        string rev=s;
        int n=rev.length();
        string result;
        int max=0;
        for(int i=0;i<n;i++){
            string c=s.substr(i,1);
            int k=i;
            while(s.find(c,k)!=std::string::npos){
                string check=s.substr(i,s.find(c,k)-i+1);
                if(check.length()>max&&pal(check)){
                    result=check;
                    max=check.length();
                }
                k=s.find(c,k)+1;
            }
        }
        return result;
    }
};