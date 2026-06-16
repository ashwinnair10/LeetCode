class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int m=0;
        int currDir=0;
        map<pair<int,int>,int> map;
        for(auto i:obstacles){
            map[{i[0],i[1]}]=1;
        }
        int x=0,y=0;
        for(auto i:commands){
            if(i==-1){
                currDir=(currDir+1)%4;
            }
            else if(i==-2){
                currDir=(currDir+3)%4;
            }
            else{
                int j;
                if(currDir==0){
                    for(j=1;j<=i;j++){
                        if(map[{x,y+j}]==1){
                            break;
                        }
                    }
                    y+=j-1;
                }
                else if(currDir==1){
                    for(j=1;j<=i;j++){
                        if(map[{x+j,y}]==1){
                            break;
                        }
                    }
                    x+=j-1;
                }
                else if(currDir==2){
                    for(j=1;j<=i;j++){
                        if(map[{x,y-j}]==1){
                            break;
                        }
                    }
                    y-=j-1;
                }
                else{
                    for(j=1;j<=i;j++){
                        if(map[{x-j,y}]==1){
                            break;
                        }
                    }
                    x-=j-1;
                }
                m=max(m,x*x+y*y);
            }
        }
        return m;
    }
};