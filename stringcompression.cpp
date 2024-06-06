class Solution {
public:
    int compress(vector<char>& s) {
        int i=0;
        while(i<s.size()-1){
            int c=1;
            while(s[i]==s[i+1]&&i+1<s.size()){
                c++;
                s.erase(s.begin()+i);
            }
            if(c!=1){
                int f=0;
                while(c!=0){
                    f++;
                    s.insert(s.begin()+i+1,(c%10)+48);
                    c/=10;
                }
                i+=f+1;
            }
            else
            i++;
        }
        return s.size();
    }
};