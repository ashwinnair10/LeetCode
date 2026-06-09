class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    int maxVowels(string s, int k) {
        int c=0;
        int n=s.length();
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                c++;
            }
        }
        int m=c;
        for(int i=1;i<=n-k;i++){
            if(isVowel(s[i-1]))
            c--;
            if(isVowel(s[i+k-1]))
            c++;
            m=max(m,c);
        }
        return m;
    }
};