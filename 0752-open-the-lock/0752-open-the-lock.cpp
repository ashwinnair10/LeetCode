class Solution {
public:
    int ans=INT_MAX;
    string change(string s,int ind,int p){
        if(p){
            if(s[ind]<'9')
            s[ind]=(s[ind]+1);
            else
            s[ind]='0';
        }
        else{
            if(s[ind]>'0')
            s[ind]=s[ind]-1;
            else
            s[ind]='9';
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit;
        for(auto i:deadends){
            visit.insert(i);
        }
        string s="0000";
        int j=0;
        queue<pair<string,int>> q;
        q.push({s,0});
        while(!q.empty()){
            string curr=q.front().first;
            int c=q.front().second;
            //cout<<"curr:"<<curr<<" c:"<<c<<'\n';
            q.pop();
            if(visit.find(curr)!=visit.end())
            continue;
            visit.insert(curr);
            if(curr==target){
                ans=min(ans,c);
                //break;
                continue;
            }
            int j=0;
            int n=4,l=0;
            while(curr[j]==target[j])
            j++;
            for(int i=j%4,l=0;l<4;l++,i=(i+1)%4){
                string s1=change(curr,i,0);
                string s2=change(curr,i,1);
                if(visit.find(s2)==visit.end()){
                    q.push({s2,c+1});
                }
                if(visit.find(s1)==visit.end()){
                    q.push({s1,c+1});
                }
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};