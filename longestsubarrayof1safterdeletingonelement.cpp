class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n=a.size();
        int len=0,maxlen=INT_MIN,c=0,ind=0;
        for(int i=0;i<n;i++){
            if(a[i]){
                len++;
            }
            else{
                if(c!=k){
                    c++;
                    len++;
                }
                else{
                    while(a[ind]){
                        ind++;
                        len--;
                    }
                    ind++;
                }
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};