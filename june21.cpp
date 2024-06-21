class Solution {
public:
    int maxSatisfied(vector<int>& a, vector<int>& b, int m) {
        int n=a.size();
        int s=0;
        for(int i=0;i<m;i++)
        s+=a[i];
        for(int i=m;i<n;i++)
        if(!b[i])
        s+=a[i];
        int ms=s;
        for(int i=1;i<n-m+1;i++){
            if(b[i-1])
            s-=a[i-1];
            if(b[i+m-1])
            s+=a[i+m-1];
            ms=max(ms,s);
        }
        return ms;
    }
};