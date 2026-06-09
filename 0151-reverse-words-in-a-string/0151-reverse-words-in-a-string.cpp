class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word="";
        for(auto i:s){
            if(i==' '){
                if(word!="")
                words.push_back(word);
                word="";
            }
            else{
                word+=i;
            }
        }
        if(word!="")
        words.push_back(word);
        string ans="";
        for(int i=words.size()-1;i>0;i--){
            ans+=words[i]+" ";
        }
        ans+=words[0];
        return ans;
    }
};