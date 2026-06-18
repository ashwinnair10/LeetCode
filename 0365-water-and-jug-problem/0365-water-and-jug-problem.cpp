class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        map<pair<int,int>,int> mp;
        queue<pair<int,int>> q;
        q.push({0,0});
        mp[{0,0}]=1;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(i==target||j==target||i+j==target)
            return true;
            if(!mp[{max(i,x),j}]){
                q.push({max(i,x),j});
                mp[{max(i,x),j}]=1;
            }
            if(!mp[{i,max(j,y)}]){
                q.push({i,max(j,y)});
                mp[{i,max(j,y)}]=1;
            }
            if(!mp[{i,0}]){
                q.push({i,0});
                mp[{i,0}]=1;
            }
            if(!mp[{0,j}]){
                q.push({0,j});
                mp[{0,j}]=1;
            }
            if(!mp[{i-min(i,y-j),min(i+j,y)}]){
                q.push({i-min(i,y-j),min(i+j,y)});
                mp[{i-min(i,y-j),min(i+j,y)}]=1;
            }
            if(!mp[{min(i+j,x),j-min(j,x-i)}]){
                q.push({min(i+j,x),j-min(j,x-i)});
                mp[{min(i+j,x),j-min(j,x-i)}]=1;
            }
        }
        return false;
    }
};