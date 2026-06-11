class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int l=0,r=potions.size()-1,m;
            int ind=-1;
            while(l<=r){
                m=l+(r-l)/2;
                if(1LL*spells[i]*potions[m]>=success){
                    ind=m;
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            if(ind!=-1)
            ans.push_back(potions.size()-ind);
            else
            ans.push_back(0);
        }
        return ans;
    }
};