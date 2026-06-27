class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int> map;
        for(auto i:nums)
        map[i]++;
        
        int ans=max(1,map[1]%2?map[1]:map[1]-1);
        for(auto i:map)
        cout<<i.first<<"**"<<i.second<<"\n";
        for(auto i:map){
            int c=0;
            long long x=i.first;
            while(true){
                cout<<x<<"\n";
                if(map[x]>1){
                    c++;
                    map[x]=0;
                }
                else if(map[x]==1){
                    c++;
                    map[x]=0;
                    break;
                }
                else{
                    map[x]=0;
                    break;
                }
                if(x>sqrt(1e9))
                break;
                x*=x;
            }
            ans=max(ans,2*c-1);
        }
        return ans;
    }
};