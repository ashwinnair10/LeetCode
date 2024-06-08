class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n=a.size();
        int l=0,r=n-1,c=0;
        while(l<r){
            if(a[l]+a[r]==k){
                c++;
                l++;
                r--;
            }
            else if(a[l]+a[r]<k){
                l++;
            }
            else{
                r--;
            }
        }
        return c;
    }
};