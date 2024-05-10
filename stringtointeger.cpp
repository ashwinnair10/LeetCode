class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        long sum=0;
        int i=0;
        while(i<s.length()){
            while(s[i]==' ')
            i++;
            if(s[i]=='-'){
                i++;
                sign=-1;
            }
            else if(s[i]=='+')
            i++;
            while(s[i]>=48&&s[i]<=57){
                sum=(sum*10)+(s[i]-48);
                if(sign==-1&&sum>=2147483648){
                    sum=-2147483648;
                    break;
                }
                if(sign==1&&sum>=2147483647){
                    sum=2147483647;
                    break;
                }
                i++;
            }
            break;
        }
        sum*=sign;
        return (int)sum;
    }
};