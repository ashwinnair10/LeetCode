class Solution {
public:
    string str(vector<int>& a){
        string s="";
        for(auto i:a){
            s+=to_string(i)+".";
        }
        return s;
    }
    void subset(vector<vector<int>>& res,unordered_set<string>& set,vector<int>& a,vector<int>& sub,int ind){
        string s=str(sub);
        if(set.find(s)==set.end()){
            res.push_back(sub);
            set.insert(s);
        }
        for(int i=ind;i<a.size();i++){
            sub.push_back(a[i]);
            subset(res,set,a,sub,i+1);
            sub.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        unordered_set<string> set;
        subset(res,set,nums,sub,0);
        return res;
    }
};