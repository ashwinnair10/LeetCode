class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n=a.size();
        vector<int> pre(n,0),suf(n,0);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i-1];
            suf[n-1-i]=suf[n-i]+a[n-i];
        }
        for(int i=0;i<n;i++){
            if(pre[i]==suf[i])
            return i;
        }
        return -1;
    }
};