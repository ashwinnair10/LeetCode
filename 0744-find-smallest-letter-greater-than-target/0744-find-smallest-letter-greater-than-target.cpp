class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> f(26,0);
        for(auto i:letters)
        f[i-'a']++;
        for(int i=target-'a'+1;i<26;i++){
            if(f[i]>0)
            return (char)(i+'a');
        }
        return letters[0];
    }
};