class Solution {
public:
    int buyChoco(vector<int>& a, int money) {
        int s1=999,s2=999,n=a.size();
        if(n==1)
        return money;
        for(int i=0;i<n;i++){
            if(a[i]<s1){
                s2=s1;
                s1=a[i];
            }
            else if(a[i]>=s1&&a[i]<s2){
                s2=a[i];
            }
        }
        if(s1>=money||money-s1-s2<0)
        return money;
        return money-s1-s2;
    }
};