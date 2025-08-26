class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double m=-1;
        int a=-1;
        for(auto i:dimensions){
            if(sqrt(pow(i[0],2)+pow(i[1],2))>m){
                m=sqrt(pow(i[0],2)+pow(i[1],2));
                a=i[0]*i[1];
            }
            else if(sqrt(pow(i[0],2)+pow(i[1],2))>=m&&i[0]*i[1]>a){
                m=sqrt(pow(i[0],2)+pow(i[1],2));
                a=i[0]*i[1];
            }
        }
        return a;
    }
};