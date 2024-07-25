class Solution {
public:
    void merge(vector<int>& a,int l,int m,int r){
        vector<int> left,right;
        for(int i=l;i<=m;i++)
        left.push_back(a[i]);
        for(int i=m+1;i<=r;i++)
        right.push_back(a[i]);
        left.push_back(INT_MAX);
        right.push_back(INT_MAX);
        int k=l;
        int i=0,j=0;
        while(k<=r){
            if(left[i]<right[j]){
                a[k++]=left[i++];
            }
            else{
                a[k++]=right[j++];
            }
        }
        return;
    }
    void mergesort(vector<int>& a,int l,int r){
        if(l>=r)
        return;
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
    vector<int> sortArray(vector<int>& a) {
        mergesort(a,0,a.size()-1);
        return a;
    }
};