class Solution {
public:
    void separate(string& s,unordered_map<string,int>& map){
        string word="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                map[word]++;
                word="";
            }
            else
            word+=s[i];
        }
        map[word]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> set1,set2;
        separate(s1,set1);
        separate(s2,set2);
        for(auto i:set1){
            if(i.second==1&&set2[i.first]==0){
                ans.push_back(i.first);
            }
        }
        for(auto i:set2){
            if(i.second==1&&set1[i.first]==0){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};