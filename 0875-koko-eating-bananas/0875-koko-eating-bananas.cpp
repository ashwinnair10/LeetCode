class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=INT_MIN;
        for(auto i:piles)
        m=max(m,i);
        int l=1,r=m,mid;
        int ans=INT_MAX,speed=INT_MAX;
        while(l<=r){
            long long s=0;
            mid=l+(r-l)/2;
            for(auto i:piles){
                s+=(i+mid-1)/mid;
            }
            if(s<=h){
                if(mid<=speed)
                speed=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return speed;
    }
};