class Solution {
public:
    bool vowel(char a){
        return (a=='a')||(a=='e')||(a=='i')||(a=='o')||(a=='u');
    }
    int maxVowels(string s, int k) {
        int c=0,mc,n=s.length();
        for(int i=0;i<k;i++){
            if(vowel(s[i]))
            c++;
        }
        mc=c;
        for(int i=1;i<n-k+1;i++){
            if(vowel(s[i-1]))
            c--;
            if(vowel(s[i+k-1]))
            c++;
            mc=max(mc,c);
        }
        return mc;
    }
};