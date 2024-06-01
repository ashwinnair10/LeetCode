class Solution {
public:
    int scoreOfString(string a) {
        int s=0;
        for(int i=0;i<a.length()-1;i++){
            s+=abs(a[i]-a[i+1]);
        }
        return s;
    }
};