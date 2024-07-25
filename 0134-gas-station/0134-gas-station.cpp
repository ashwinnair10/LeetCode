class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0;
        int ind=-1;
        for(int i=0;i<gas.size();i++){
            tot+=gas[i]-cost[i];
            int curr=gas[i]-cost[i];
            if(curr<0){
                ind=(i+1)%gas.size();
            }
        }
        if(tot<0)
        return -1;
        return ind;
    }
};