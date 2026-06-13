class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        hBars.push_back(1);
        // hBars.push_back(n+2);
        vBars.push_back(1);
        // vBars.push_back(m+2);
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int sh=1,msh=0,i;
        for(i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1){

            }
            else{
                msh=max(msh,hBars[i-1]+1-sh);
                sh=hBars[i]-1;
            }
            cout<<"i : "<<i<<" , hBars[i] : "<<hBars[i]<<" , msh : "<<msh<<"\n";
        }
        msh=max(msh,hBars[i-1]+1-sh);
        // cout<<"i : "<<i<<" , hBars[i] : "<<hBars[i]<<" , msh : "<<msh<<"\n";
        



        cout<<"Max horizontal side : "<<msh<<"\n";
        
        int sv=1,msv=0;
        for(i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1){

            }
            else{
                msv=max(msv,vBars[i-1]+1-sv);
                sv=vBars[i]-1;
            }
            cout<<"i : "<<i<<" , vBars[i] : "<<vBars[i]<<" , msv : "<<msv<<"\n";
        }
        msv=max(msv,vBars[i-1]+1-sv);
        // cout<<"i : "<<i<<" , vBars[i] : "<<vBars[i]<<" , msv : "<<msv<<"\n";



        cout<<"Max vertical side : "<<msv<<"\n";
        int s=min(msh,msv);
        return s*s;
    }
};