class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        if(!n||n==1)
        return;
        int l=0,r=1;
        while(l<=r&&r<a.size()){
            if(a[l]!=0){
                l++;
                r++;
            }
            else if(!a[l]&&!a[r])
            r++;
            else if(!a[l]&&a[r]){
                int t=a[l];
                a[l]=a[r];
                a[r]=t;
                r++;
                l++;
            }
        }
        return;
    }
};