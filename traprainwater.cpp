class Solution {
public:
    int trap(vector<int>& height) {
        int total=0;
        int n=height.size();
        vector<int>l(n,INT_MIN),r(n,INT_MIN);
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            m=max(m,height[i]);
            l[i]=m;
        }
        m=INT_MIN;
        for(int i=n-1;i>-1;i--){
            m=max(m,height[i]);
            r[i]=m;
        }
        for(int i=0;i<n;i++){
            total+=min(l[i],r[i])-height[i];
        }
        return total;
    }
};