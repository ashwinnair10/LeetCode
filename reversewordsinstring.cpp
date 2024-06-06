class Solution {
public:
    string reverseWords(string s) {
        string str="";
        while(s!=""){
            while(s[0]==' ')
            s.erase(0,1);
            if(s.find(" ")!=std::string::npos){
                str=s.substr(0,s.find(" "))+" "+str;
                s.erase(0,s.find(" ")+1);
            }
            else{
                str=s.substr(0,s.length())+" "+str;
                s.erase(0,s.length());
            }
        }
        while(str[0]==' ')
        str.erase(0,1);
        while(str[str.length()-1]==' ')
        str.erase(str.length()-1,1);
        return str;
    }
};