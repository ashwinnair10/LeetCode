class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        vector<int> s(10,0),g(10,0);
        for(int i=0;i<secret.length();i++){
            s[secret[i]-48]++;
            g[guess[i]-48]++;
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
                s[secret[i]-48]--;
                g[guess[i]-48]--;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(s[i],g[i]);
        }
        string ans="";
        if(bulls){
            string num="";
            while(bulls){
                num=(char)(bulls%10+48)+num;
                bulls/=10;
            }
            ans+=num;
        }
        else{
            ans+="0";
        }
        ans+="A";
        if(cows){
            string num="";
            while(cows){
                num=(char)(cows%10+48)+num;
                cows/=10;
            }
            ans+=num;
        }
        else{
            ans+="0";
        }
        ans+="B";
        return ans;
    }
};