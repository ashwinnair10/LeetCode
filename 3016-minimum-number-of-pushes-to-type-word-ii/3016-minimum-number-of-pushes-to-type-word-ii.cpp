class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(auto i:word)
        v[i-97]++;
        sort(v.begin(),v.end());
        for(int i=25;i>=0;i--)
        cout<<v[i]<<'\n';
        int t=1,s=0,ans=0;
        for(int i=25;i>=0;i--){
            if(v[i]==0)
            break;
            cout<<t;
            ans+=v[i]*t;
            s++;
            if(s%8==0)
            t++;
        }
        return ans;
    }
};