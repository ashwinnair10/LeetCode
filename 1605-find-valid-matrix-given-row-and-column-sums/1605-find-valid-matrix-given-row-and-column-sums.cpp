class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        vector<vector<int>> a(r.size(),vector<int>(c.size(),0));
        int m=r.size(),n=a[0].size();
        for(int j=0;j<m*n;j++){
        int rm=INT_MAX,rmi,cm=INT_MAX,cmi;
        for(int i=0;i<r.size();i++){
            if(r[i]&&r[i]<rm){
                rm=r[i];
                rmi=i;
            }
        }
        for(int i=0;i<c.size();i++){
            if(c[i]&&c[i]<cm){
                cm=c[i];
                cmi=i;
            }
        }
        //cout<<"rm : "<<rm<<" rmi: "<<rmi<<" cm: "<<cm<<" cmi: "<<cmi<<'\n';
        if(rm<cm){
            for(int i=0;i<n;i++){
                if(c[i]&&!a[rmi][i]){
                    a[rmi][i]=rm;
                    c[i]-=rm;
                    r[rmi]-=rm;
                    break;
                }
            }
        }
        else{
            for(int i=0;i<m;i++){
                if(r[i]&&!a[i][cmi]){
                    a[i][cmi]=cm;
                    r[i]-=cm;
                    c[cmi]-=cm;
                    break;
                }
            }
        }
        // cout<<"Matrix\n";
        // for(int k=0;k<m;k++){
        //     for(int l=0;l<n;l++){
        //         cout<<a[k][l]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<"ROW\n";
        // for(auto i:r)
        // cout<<i<<' ';
        // cout<<'\n';
        // cout<<"COLUMN\n";
        // for(auto i:c)
        // cout<<i<<' ';
        // cout<<'\n';
        }
        return a;
    }
};