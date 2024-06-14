class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        sort(a.begin(),a.end());
        int c=0;
        for(int i=1;i<a.size();i++){
            if(a[i]<=a[i-1]){
                c+=a[i-1]+1-a[i];
                a[i]=a[i-1]+1;
            }
        }
        return c;
    }
};