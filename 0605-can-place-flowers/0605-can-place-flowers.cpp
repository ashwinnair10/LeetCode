class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(f.size()==1){
            return (n==1&&f[0]==0)||n==0;
        }
        int c=0;
        if(!f[0]&&!f[1]){
            c++;
            f[0]=1;
        }
        for(int i=1;i<f.size()-1;i++){
            if(!f[i]&&!f[i-1]&&!f[i+1]){
                f[i]=1;
                c++;
            }
        }
        if(!f[f.size()-2]&&!f[f.size()-1]){
            c++;
            f[f.size()-1]=1;
        }
        return c>=n;
    }
};