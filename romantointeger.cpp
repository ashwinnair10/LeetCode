class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='I'){
                num+=1;
            }
            else if(s[i]=='V'&&i-1>=0&&s[i-1]=='I'){
                num+=4;
                i--;
            }
            else if(s[i]=='V'){
                num+=5;
            }
            else if(s[i]=='X'&&i-1>=0&&s[i-1]=='I'){
                num+=9;
                i--;
            }
            else if(s[i]=='X'){
                num+=10;
            }
            else if(s[i]=='L'&&i-1>=0&&s[i-1]=='X'){
                num+=40;
                i--;
            }
            else if(s[i]=='L'){
                num+=50;
            }
            else if(s[i]=='C'&&i-1>=0&&s[i-1]=='X'){
                num+=90;
                i--;
            }
            else if(s[i]=='C'){
                num+=100;
            }
            else if(s[i]=='D'&&i-1>=0&&s[i-1]=='C'){
                num+=400;
                i--;
            }
            else if(s[i]=='D'){
                num+=500;
            }
            else if(s[i]=='M'&&i-1>=0&&s[i-1]=='C'){
                num+=900;
                i--;
            }
            else if(s[i]=='M'){
                num+=1000;
            }
        }
        return num;
    }
};