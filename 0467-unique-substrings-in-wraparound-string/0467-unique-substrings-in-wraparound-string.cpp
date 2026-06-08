class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int ans=0;
        int curr=0,l=0;
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            if(l==0){
                curr=s[i]-97;
                l++;
                count[s[i]-97]=max(count[s[i]-97],l);
            }
            else{
                if(s[i]-97==(curr+1)%26){
                    l++;
                    curr=(curr+1)%26;
                    count[s[i]-97]=max(count[s[i]-97],l);
                }
                else{
                    l=0;
                    i--;
                }
            }
        }
        count[s[s.length()-1]-97]=max(count[s[s.length()-1]-97],l);
        for(int i=0;i<26;i++){
            cout<<(char)(i+97)<<" : "<<count[i]<<'\n';
            ans+=count[i];
        }
        return ans;
    }
};