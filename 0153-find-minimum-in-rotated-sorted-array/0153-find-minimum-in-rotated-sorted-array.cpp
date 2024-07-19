class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0,r=a.size()-1;
        int ans=INT_MAX;
        while(l<r){
            int m=(l+r)/2;
            if(a[m]<a[r]){
                r=m;
            }
            else l=m+1;
        }
        return a[l];
    }
};