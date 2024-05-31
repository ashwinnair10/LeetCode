class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int c=0,a;
        int n=arr.size();
        for(int i=0;i<n;i++){
            a=arr[i];
            for(int k=i+1;k<n;k++){
                a^=arr[k];
                if(!a)
                c+=k-i;
            }
        }
        return c;
    }
};