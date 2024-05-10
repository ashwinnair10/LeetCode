class Solution {
public:
    string convert(string s, int r) {
        if(r==1)
        return s;
        int d=1;
        int n=s.length();
        char zig[r][n];
        for(int i=0;i<r;i++)
        for(int j=0;j<n;j++)
        zig[i][j]='0';
        int j=0,k=0;
        for(int i=0;i<n;i++){
            zig[j][k]=s[i];
            if(d){
                if(j==r-1){
                    d=0;
                    j--;
                    k++;
                    continue;
                }
                j++;
            }
            else{
                if(!j){
                    d=1;
                    j++;
                    continue;
                }
                j--;
                k++;
            }
        }
        string ch="";
        for(int i=0;i<r;i++)
        for(int j=0;j<n;j++)
        if(zig[i][j]!='0')
        ch.push_back(zig[i][j]);
        return ch;
    }
};