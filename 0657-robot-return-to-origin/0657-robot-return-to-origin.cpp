class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0,u=0;
        for(auto i:moves){
            if(i=='L')
            l++;
            else if(i=='R')
            l--;
            else if(i=='U')
            u++;
            else u--;
        }
        return !l&&!u;
    }
};