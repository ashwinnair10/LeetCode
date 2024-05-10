class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        long rev=0;
        while(x!=0){
            rev=(rev*10)+(x%10);
            x/=10;
        }
        cout<<rev<<'\n';
        if(rev<-2147483648||rev>2147483647)
        rev=-1;
        return y==rev&&rev>=0?true:false;
    }
};