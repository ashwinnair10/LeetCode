class Solution {
public:
    int reverse(int x) {
        long s=0;
        int c=x>=0?0:1;
        while(x!=0){
            s=(s*10)+(x%10);
            x/=10;
        }
        if(!c&&s<=2147483647)
        return s;
        if(c&&s>=-2147483648)
        return s;
        return 0;
    }
};