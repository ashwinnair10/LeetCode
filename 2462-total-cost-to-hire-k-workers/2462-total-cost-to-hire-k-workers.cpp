class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int,vector<int>,greater<int>> p1,p2;
        int left=0,right=n-1;
        int h=0;
        while(h<candidates&&left<=right){
            p1.push(costs[left++]);
            h++;
        }
        h=0;
        while(h<candidates&&left<=right){
            p2.push(costs[right--]);
            h++;
        }
        h=0;
        long long ans=0;
        for(int i=0;i<k;i++){
            int v1=p1.empty()?INT_MAX:p1.top();
            int v2=p2.empty()?INT_MAX:p2.top();
            if(v1<=v2){
                ans+=v1;
                p1.pop();
                if(left<=right){
                    p1.push(costs[left++]);
                }
            }
            else{
                ans+=v2;
                p2.pop();
                if(left<=right){
                    p2.push(costs[right--]);
                }
            }
        }
        return ans;
    }
};