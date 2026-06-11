class Solution {
public:
    int findPeakElement(vector<int>& a) {
        a.insert(a.begin(),INT_MIN);
        a.push_back(INT_MIN);
        int l=1,r=a.size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(a[m]>a[m-1]&&a[m]>a[m+1])
            return m-1;
            else if(a[m-1]<a[m])
            l=m+1;
            else
            r=m-1;
        }
        return 0;
    }
};