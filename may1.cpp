class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.find(ch,0)==std::string::npos)
        return word;
        int ind=word.find(ch,0);
        for(int i=0;i<=ind/2;i++)
        swap(word[i],word[ind-i]);
        return word;
    }
};