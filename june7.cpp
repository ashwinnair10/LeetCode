class Solution {
public:
    int check(string& s,string& t){
        if(s.length()<=t.length())
        return 0;
        for(int i=0;i<t.length();i++){
            if(s[i]!=t[i])
            return 0;
        }
        return 1;
    }
    string replaceWords(vector<string>& words, string s) {
        int ind=0,l=INT_MAX,f=0;
        string res,test,word;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '||i==s.length()-1){
                l=INT_MAX;
                test="";
                if(i==s.length()-1)
                word+=s[i];
                for(int j=0;j<words.size();j++){
                    if(check(word,words[j])&&words[j].length()<l){
                        f++;
                        l=words[j].length();
                        test=words[j]+" ";
                    }
                }
                if(!f)
                res+=word+" ";
                else
                res+=test;
                f=0;
                ind=i+1;
                word="";
            }
            else{
                word+=s[i];
            }
        }
        return res.erase(res.length()-1,1);
    }
};