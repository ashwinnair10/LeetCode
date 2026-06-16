class Robot {
public:
    vector<vector<int>> grid;
    int m,n;
    int dir;//0N,1E,2S,3W
    int x,y;
    int p;
    Robot(int width, int height) {
        grid.resize(width,vector<int>(height));
        m=width,n=height;
        dir=1;
        x=0,y=0;
        p=2*(m+n-2);
    }
    
    void step(int num) {
        if(!p)
        return;
        num%=p;
        if(!num){
            if(x||y)
            return;
            else
            dir=2;
        }
        while(num>0){
            if(dir==1){
                int move=min(num,m-1-x);
                x+=move;
                num-=move;
                if(num>0) dir=0;
            } 
            else if(dir==0){
                int move=min(num,n-1-y);
                y+=move;
                num-=move;
                if(num>0) dir=3;
            } 
            else if(dir==3){
                int move=min(num,x);
                x-=move;
                num-=move;
                if(num>0) dir=2;
            } 
            else {
                int move=min(num,y);
                y-=move;
                num-=move;
                if(num>0) dir=1;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        switch(dir){
            case 0: return "North";
            case 1: return "East";
            case 2: return "South";
            case 3: return "West";
            default: return "";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */