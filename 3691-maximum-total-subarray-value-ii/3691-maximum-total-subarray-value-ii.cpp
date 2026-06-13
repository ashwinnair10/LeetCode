class Solution {
public:
    void buildTree(vector<int>& nums,vector<pair<int,int>>& st,int node,int l,int r){
        if(l==r){
            st[node]={nums[l],nums[l]};
            return;
        }
        int m=l+(r-l)/2;
        buildTree(nums,st,2*node,l,m);
        buildTree(nums,st,2*node+1,m+1,r);
        st[node]={min(st[2*node].first,st[2*node+1].first),max(st[2*node].second,st[2*node+1].second)};
        return;
    }
    pair<int,int> query(vector<pair<int,int>>& st,int node,int l,int r,int tl,int tr){
        if(tl<=l&&r<=tr){
            return st[node];
        }
        if(r<tl||l>tr){
            return {INT_MAX,INT_MIN};
        }
        int m=l+(r-l)/2;
        auto left=query(st,2*node,l,m,tl,tr);
        auto right=query(st,2*node+1,m+1,r,tl,tr);
        return {min(left.first,right.first),max(left.second,right.second)};
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        set<vector<int>> visit;
        int n=nums.size();
        vector<pair<int,int>> st(4*n);
        buildTree(nums,st,1,0,n-1);
        for(int i=0;i<n;i++){
            auto res=query(st,1,0,n-1,i,n-1);
            pq.push({res.second-res.first,{i,n-1}});
            visit.insert({i,n-1});
        }
        long long s=0;
        int l,r;
        while(!pq.empty()&&k-->0){
            s+=pq.top().first;
            l=pq.top().second[0];
            r=pq.top().second[1];
            pq.pop();
            if(l<r){
                if(visit.find({l+1,r})==visit.end()){
                    visit.insert({l+1,r});
                    auto res=query(st,1,0,n-1,l+1,r);
                    pq.push({res.second-res.first,{l+1,r}});
                }
                if(visit.find({l,r-1})==visit.end()){
                    visit.insert({l,r-1});
                    auto res=query(st,1,0,n-1,l,r-1);
                    pq.push({res.second-res.first,{l,r-1}});
                }
            }
        }
        return s;
    }
};