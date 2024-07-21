class Solution {
public:
    bool cycle=false;
    vector<int> topo(vector<vector<int>>& a){
        int k=a.size();
        vector<int> in(k,0);
        for(int i=0;i<k;i++){
            for(int j=0;j<a[i].size();j++)
            in[a[i][j]]++;
        }
        queue<int> q;
        vector<int> tp;
        for(int i=0;i<k;i++)
        if(in[i]==0){
            q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            tp.push_back(curr+1);
            q.pop();
            for(int i=0;i<a[curr].size();i++){
                in[a[curr][i]]--;
                if(in[a[curr][i]]==0)
                q.push(a[curr][i]);
            }
        }
        if(tp.size()==k) 
        return tp;
        cycle=true;
        return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        vector<vector<int>> ra(k),ca(k);
        for(auto i:r){
            ra[i[0]-1].push_back(i[1]-1);
        }
        for(auto i:c){
            ca[i[0]-1].push_back(i[1]-1);
        }
        vector<int> row=topo(ra);
        vector<int> col=topo(ca);
        if(cycle)
        return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        unordered_map<int,int> rm,cm;
        for(int i=0;i<k;i++){
            rm[row[i]]=i;
            cm[col[i]]=i;
        }
        for(int i=1;i<=k;i++){
            ans[rm[i]][cm[i]]=i;
        }
        return ans;
    }
};