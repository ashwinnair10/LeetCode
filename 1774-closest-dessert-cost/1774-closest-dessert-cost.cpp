class Solution {
public:
    void test(int& ans,int& md,int sum,vector<int>& top,int ind,int target){
        if(abs(sum-target)<=md){
            if(md==abs(sum-target)){
                ans=min(ans,sum);
            }
            else
            ans=sum;
            md=abs(sum-target);
        }
        if(ind>=top.size())
        return;
        test(ans,md,sum,top,ind+1,target);
        test(ans,md,sum+top[ind],top,ind+1,target);
        test(ans,md,sum+2*top[ind],top,ind+1,target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans=INT_MAX,md=INT_MAX;
        for(auto i:baseCosts){
            test(ans,md,i,toppingCosts,0,target);
        }
        return ans;
    }
};