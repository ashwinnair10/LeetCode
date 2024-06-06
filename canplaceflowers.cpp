class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int i=0;
        while(i<a.size()&&n){
            if(!i&&!a[i]){
                if(i+1<a.size()){
                    if(!a[i+1]){
                        a[i]=1;
                        n--;
                    }
                }
                else{
                    a[i]=1;
                    n--;
                }
            }
            else if(i==a.size()-1&&!a[i]){
                if(i-1>-1){
                    if(!a[i-1]){
                        a[i]=1;
                        n--;
                    }
                }
                else{
                    a[i]=1;
                    n--;
                }
            }
            else if(!a[i]){
                if(!a[i-1]&&!a[i+1]){
                    a[i]=1;
                    n--;
                }
            }
            i++;
        }
        return n?false:true;
    }
};