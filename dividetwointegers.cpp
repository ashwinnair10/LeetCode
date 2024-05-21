class Solution {
public:
    int divide(int s, int t) {
        if(t==1)
        return s;
        if(t==-1&&s!=INT_MIN)
        return -s;
        if(t==-1&&s==INT_MIN)
        return INT_MAX;
        int c=0,sign;
        sign=(((double)s/t)>=0)?1:-1;
        cout<<sign;
        if(sign==1){
            if(s>=0&&s<t)
            return 0;
            if(s<0&&s>t)
            return 0;
            if(s>=0){
                while(s>=t){
                    s-=t;
                    c++;
                }
            }
            else{
                while(s<=t){
                    s-=t;
                    c++;
                }
            }
            return c;
        }
        else{
            if(s>0)
            s=-s;
            if(t>0)
            t=-t;
            if(s>t)
            return 0;
            while(s<=t){
                s-=t;
                c++;
            }
            return -c;
        }
        return 0;
    }
};