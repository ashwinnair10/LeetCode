class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> map;
        for(auto i:cpdomains){
            string s="";
            int n=0;
            for(int j=0;j<i.length();j++){
                if(i[j]==' ')
                break;
                n=(n*10)+(i[j]-'0');
            }
            string d="";
            for(int j=i.length()-1;j>=0;j--){
                if(i[j]=='.'){
                    reverse(s.begin(),s.end());
                    d=s+d;
                    map[d]+=n;
                    s="";
                }
                else if(i[j]==' '){
                    reverse(s.begin(),s.end());
                    d=s+d;
                    map[d]+=n;
                    break;
                }
                s+=i[j];
            }
        }
        vector<string> ans;
        for(auto i:map){
            ans.push_back(to_string(i.second)+" "+i.first);
        }
        return ans;
    }
};