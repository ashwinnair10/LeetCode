class Solution {
    public:
    void util(string &s,vector<string> &ans,string curr,int ind,int curr_sec_count)
    {
        if(curr_sec_count == 4 && (s.length() == ind)){
            ans.push_back(curr);
            return;
        }   
        if((s.length()-ind) > 3*(4-curr_sec_count) || ind >= s.length())
        return;
        for(int i=1;i<=3;i++)
        {
            string curr_sec = s.substr(ind,i);
            if((curr_sec.length()>1 && curr_sec[0]=='0')|| stoi(curr_sec)>255)
               continue;
            string temp = curr_sec_count == 0 ? curr_sec : (curr + "." + curr_sec);
            util(s,ans,temp,ind+i,curr_sec_count+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans; 
        util(s,ans,"",0,0);
        return ans;
    }
};