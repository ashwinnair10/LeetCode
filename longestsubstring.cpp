class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subs;
        int t=0,max=0;
        for(int i=0;i<s.length();i++){
            if(subs.find(s[i])==std::string::npos){
                subs+=s[i];
                if((int)subs.length()>max)
                max=subs.length();
            }
            else{
                int t=subs.find(s[i]);
                while(t!=-1){
                    subs.erase(0,1);
                    t--;
                }
                subs+=s[i];
                if((int)subs.length()>max)
                max=subs.length();
            }
        }
        return max;
    }
};