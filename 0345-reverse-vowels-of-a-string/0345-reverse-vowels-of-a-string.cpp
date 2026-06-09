class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string reverseVowels(string s) {
        vector<char> vowels;
        for(auto i:s){
            if(isVowel(i))
            vowels.push_back(i);
        }
        int n=vowels.size(),j=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=vowels[n-1-j];
                j++;
            }
        }
        return s;
    }
};