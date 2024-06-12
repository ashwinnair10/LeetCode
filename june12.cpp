class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        int j=0,t,i;
        while(j<n&&!a[j])
        j++;
        for(i=j+1;i<n;i++){
            if(!a[i]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                while(j<n&&!a[j]){
                    j++;
                }
            }
        }
        while(j<n&&a[j]==1)
        j++;
        for(i=j+1;i<n;i++){
            if(a[i]==1){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                while(j<n&&a[j]==1){
                    j++;
                }
            }
        }
        return;
    }
};