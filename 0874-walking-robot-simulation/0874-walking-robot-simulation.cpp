class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //0-north,1-east,2-south,3-west
        int m=0;
        int currDir=0;
        map<pair<int,int>,int> map;
        cout<<"Obstacles\n";
        for(auto i:obstacles){
            map[{i[0],i[1]}]=1;
            cout<<"map["<<i[0]<<","<<i[1]<<"]="<<map[{i[0],i[1]}]<<"\n";
        }
        cout<<"---------------------------------------\n";
        int x=0,y=0;
        cout<<"x : "<<x<<" , y : "<<y<<" , currDir : "<<currDir<<"\n";
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
                        // cout<<"map["<<x+j<<","<<y<<"]="<<map[{x+j,y}]<<"\n";
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
                cout<<"x : "<<x<<" , y : "<<y<<" , currDir : "<<currDir<<"\n";
            }
        }
        return m;
    }
};