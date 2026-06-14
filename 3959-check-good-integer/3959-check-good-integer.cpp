class Solution {
public:
    int test(int n,int a){
        int s=0;
        while(n>0){
            if(a)
            s+=(n%10)*(n%10);
            else
            s+=n%10;
            n/=10;
        }
        return s;
    }
    bool checkGoodInteger(int n) {
        return test(n,1)-test(n,0)>=50;
    }
};