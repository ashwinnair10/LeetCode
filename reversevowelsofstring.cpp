class Solution {
public:
    int vowel(char a){
        return (a=='a'||a=='A'||a=='e'||a=='E'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U')?1:0;
    }
    string reverseVowels(string s) {
        vector<char> vec;
        int l=0,r=s.size()-1;
        while(l<=r){
            if(vowel(s[l])&&vowel(s[r])){
                char t=s[l];
                s[l]=s[r];
                s[r]=t;
                l++;
                r--;
            }
            else if(vowel(s[l])){
                r--;
            }
            else if(vowel(s[r])){
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        return s;
    }
};