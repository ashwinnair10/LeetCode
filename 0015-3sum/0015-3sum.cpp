class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        for(int i=0;i<a.size();i++){
            int l=i+1,r=a.size()-1;
            while(l<r){
                int left=a[l],right=a[r];
                if(left+right==-a[i]){
                    ans.push_back({left,right,a[i]});
                    while(l<a.size()&&a[l]==left)
                    l++;
                    while(r>=0&&a[r]==right)
                    r--;
                }
                else if(a[l]+a[r]<-a[i]){
                    while(l<a.size()&&a[l]==left)
                    l++;
                }
                else{
                    while(r>=0&&a[r]==right)
                    r--;
                }
            }
            int curr=a[i];
            while(i<a.size()&&a[i]==curr)
            i++;
            i--;
        }
        return ans;
    }
};