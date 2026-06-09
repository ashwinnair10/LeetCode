class Solution {
public:
    int compress(vector<char>& chars) {
        int len=0,c=0;
        char s='\n';
        for(int i=0;i<chars.size();i++){
            if(chars[i]!=s){
                if(s!='\n'){
                    chars[len++]=s;
                    if(c>1){
                        string num=to_string(c);
                        for(auto j:num){
                            chars[len++]=j;
                        }
                    }
                }
                c=1;
                s=chars[i];
            }
            else{
                c++;
            }
        }
        chars[len++]=s;
        if(c>1){
            string num=to_string(c);
            for(auto j:num){
                chars[len++]=j;
            }
        }
        return len;
    }
};