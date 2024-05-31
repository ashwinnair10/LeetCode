class Solution {
public:
    int numSteps(string s) {
        int c=0;
        while(s!="1"){
            c++;
            if(s[s.length()-1]=='0'){
                s=s.substr(0,s.length()-1);
            }
            else{
                int j;
                for(j=s.length()-1;j>-1;j--){
                    if(s[j]=='1'){
                        s[j]='0';
                    }
                    else{
                        s[j]='1';
                        break;
                    }
                }
                if(j==-1)
                s='1'+s;
            }
        }
        return c;
    }
};