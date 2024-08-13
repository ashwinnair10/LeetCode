class Solution {
public:
    string transform(vector<int>& sub){
        string str="";
        for(int i=0;i<sub.size();i++){
            str.append(to_string(sub[i]));
            str.append(".");
        }
        return str;
    }
    void calc(vector<vector<int>>& res,vector<int>& sub,vector<int>& a,int target,int index,unordered_set<string>& set){
        if(target==0){
            string k=transform(sub);
            if(set.find(k)==set.end()){
                res.push_back(sub);
                set.insert(k);
            }
            return;
        }
        if(target<0){
            return;
        }
        if(index==a.size()){
            return;
        }
        sub.push_back(a[index]);
        calc(res,sub,a,target-a[index],index+1,set);
        sub.pop_back();
        while(index<a.size()-1&&a[index]==a[index+1])
        index++;
        calc(res,sub,a,target,index+1,set);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        unordered_set<string> set;
        sort(a.begin(),a.end());
        calc(res,sub,a,target,0,set);
        return res;
    }
};