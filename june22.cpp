class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        vector<int> vec;
        vec.push_back(0);
        for(int i=0;i<a.size();i++){
            if(a[i]%2){
                vec.push_back(i);
            }
        }
        vec.push_back(a.size()-1);
        int count=0;
        int n=vec.size();
        if(n-2<k)
        return 0;
        for(int i=1;i<n-k;i++){
            if(vec[i]!=vec[i-1]){
                if(vec[i+k]!=vec[i+k-1]){
                    if(i==1&&i+k!=n-1)
                    count+=(vec[i]-vec[i-1]+1)*(vec[i+k]-vec[i+k-1]);
                    else if(i==1&&i+k==n-1)
                    count+=(vec[i]-vec[i-1]+1)*(vec[i+k]-vec[i+k-1]+1);
                    else if(i+k==n-1)
                    count+=(vec[i]-vec[i-1])*(vec[i+k]-vec[i+k-1]+1);
                    else
                    count+=(vec[i]-vec[i-1])*(vec[i+k]-vec[i+k-1]);
                }
                else{
                    count+=(vec[i]-vec[i-1]);
                }
            }
            else{
                if(vec[i+k]!=vec[i+k-1]){
                    count+=(vec[i+k]-vec[i+k-1]);
                }
                else{
                    count++;
                }
            }
        }
        return count;
    }
};