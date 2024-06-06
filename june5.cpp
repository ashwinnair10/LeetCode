class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> map(26,0),m(26,0);
        for(int i=0;i<words[0].length();i++){
            map[words[0][i]-97]++;
        }
        for(int i=1;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                m[words[i][j]-97]++;
            }
            for(int i=0;i<26;i++){
                if(map[i]&&!m[i])
                map[i]=0;
                else{
                    if(m[i]<map[i])
                    map[i]=m[i];
                }
                m[i]=0;
            }
        }
        string k="";
        vector<string> vec;
        for(int i=0;i<26;i++){
            while(map[i]--){
                char ch=i+97;
                vec.push_back(k+ch);
            }
        }
        return vec;
    }
};