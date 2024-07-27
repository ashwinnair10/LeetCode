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
        if(visit.find(s)!=visit.end())
        return -1;
        int j=0;
        queue<pair<string,int>> q;
        q.push({s,0});
        while(!q.empty()){
            string curr=q.front().first;
            int c=q.front().second;
            q.pop();
            if(curr==target){
                ans=min(ans,c);
                continue;
            }
            int j=0;
            int n=4,l=0;
            for(int i=j%4,l=0;l<4;l++,i=(i+1)%4){
                string s1=change(curr,i,0);
                string s2=change(curr,i,1);
                if(visit.find(s2)==visit.end()){
                    q.push({s2,c+1});
                    visit.insert(s2);
                }
                if(visit.find(s1)==visit.end()){
                    q.push({s1,c+1});
                    visit.insert(s1);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};