class Solution {
public:
    string parse(int h,int m){
        if(h>=12||m>59)
        return "";
        string ans="";
        ans+=to_string(h)+":";
        if(m<10)
        ans+="0";
        ans+=to_string(m);
        return ans;
    }
    void test(vector<string>& ans,int h,int m,int n,vector<pair<int,int>>& v,int ind){
        if(n==0){
            string s=parse(h,m);
            if(s!="")
            ans.push_back(s);
            return;
        }
        if(ind>=v.size())
        return;
        if(v[ind].second==0){
            test(ans,h+v[ind].first,m,n-1,v,ind+1);
            test(ans,h,m,n,v,ind+1);
        }
        else{
            test(ans,h,m+v[ind].first,n-1,v,ind+1);
            test(ans,h,m,n,v,ind+1);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        vector<pair<int,int>> v={{8,0},{4,0},{2,0},{1,0},{32,1},{16,1},{8,1},{4,1},{2,1},{1,1}};
        int h=0,m=0;
        test(ans,h,m,turnedOn,v,0);
        return ans;
    }
};