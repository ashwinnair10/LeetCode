class Solution {
public:
    int pivotInteger(int n) {
        int l=0,r=0;
        for(int i=1;i<=n;i++){
            r+=i;
        }
        for(int i=1;i<=n;i++){
            l+=i;
            if(l==r)
            return i;
            r-=i;
        }
        return -1;
    }
};