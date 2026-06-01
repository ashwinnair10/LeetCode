class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        long long y=0,num=x;
        while(num){
            y=y*10+(num%10);
            num/=10;
        }
        return x==y;
    }
};