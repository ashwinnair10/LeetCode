class Solution {
public:
    string convertToBase7(int num) {
        if(!num)
        return "0";
        string ans="";
        int p=num>=0?1:-1;
        num=abs(num);
        while(num>0){
            ans=(char)(num%7+'0')+ans;
            num/=7;
        }
        return p>0?ans:"-"+ans;
    }
};