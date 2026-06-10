class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r,d;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R')
            r.push(i);
            else
            d.push(i);
        }
        while(r.size()!=0&&d.size()!=0){
            if(r.front()<d.front()){
                d.pop();
                r.push(r.front()+s.length());
                r.pop();
            }
            else{
                r.pop();
                d.push(d.front()+s.length());
                d.pop();
            }
        }
        return r.size()==0?"Dire":"Radiant";
    }
};