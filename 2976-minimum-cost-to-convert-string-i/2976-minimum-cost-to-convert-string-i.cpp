class Solution {
public:
    int inf=INT_MAX;
    long long minimumCost(string src, string target, vector<char>& og, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26,vector<int>(26,inf));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<og.size();i++){
            dist[og[i]-97][changed[i]-97]=min(dist[og[i]-97][changed[i]-97],cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=inf&&dist[k][j]!=inf&&dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<26;j++){
        //         if(dist[i][j]!=inf){
        //             cout<<(char)(i+97)<<' '<<(char)(j+97)<<' '<<dist[i][j]<<'\n';
        //         }
        //     }
        // }
        long long mincost=0;
        for(int i=0;i<src.length();i++){
            if(dist[src[i]-97][target[i]-97]==inf){
                cout<<src[i]<<target[i]<<'\n';
                return -1;
            }
            else if(src[i]==target[i])
            continue;
            else if(dist[src[i]-97][target[i]-97]!=inf)
            mincost+=dist[src[i]-97][target[i]-97];
        }
        return mincost;
    }
};