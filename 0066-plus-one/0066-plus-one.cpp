class Solution {
public:
    vector<int> plusOne(vector<int>& s) {
        int i=s.size()-1;
        while(i>-1&&s[i]==9){
            s[i]=0;
            i--;
        }
        if(i==-1)
        s.insert(s.begin()+0,1);
        else
        s[i]+=1;
        return s;
    }
};