class Solution {
public:
    int findMinDifference(vector<string>& a) {
        int ans=INT_MAX;
        vector<vector<int>> v(24,vector<int>(60,0));
        for(int i=0;i<a.size();i++){
            //cout<<stoi(a[i].substr(0,2))<<" "<<stoi(a[i].substr(3,2))<<"\n";
            if(v[stoi(a[i].substr(0,2))][stoi(a[i].substr(3,2))]==1)
            return 0;
            v[stoi(a[i].substr(0,2))][stoi(a[i].substr(3,2))]=1;
        }
        int si=-1,sj=-1;
        int i=0,j=0,c=0;
        while(!(i==si&&j==sj)){
            if(v[i][j]==1){
                if(si==-1&&sj==-1){
                    si=i;
                    sj=j;
                    c=0;
                }
                else{
                    ans=min(ans,c);
                    c=0;
                }
            }
            c++;
            cout<<"c:"<<c<<'\n';
            j=(j+1)%60;
            if(!j)
            i=(i+1)%24;
        }
        cout<<si<<" "<<sj;
        return min(ans,c);
    }
};