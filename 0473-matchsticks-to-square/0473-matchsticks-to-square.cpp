class Solution {
public:
    bool test(vector<int>& m,vector<int>& side,int ind,int target){
        if(ind>=m.size()){
            if(side[0]==side[1]&&side[1]==side[2]&&side[2]==side[3]){
                return true;
            }
            return false;
        }
        bool f=false;
        for(int i=0;i<4;i++){
            if(side[i]+m[ind]>target)
            continue;
            side[i]+=m[ind];
            f=f || test(m,side,ind+1,target);
            side[i]-=m[ind];
            if(f)
            return true;
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        int s=0;
        for(auto i:m)
        s+=i;
        if(s%4!=0)
        return false;
        int target=s/4;
        vector<int> side(4,0);
        sort(m.rbegin(),m.rend());
        return test(m,side,0,target);
    }
};