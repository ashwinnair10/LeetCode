class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        class Union{
            vector<int> parent,size;
            int c;
            public:
            Union(int n){
                parent.resize(n);
                size.resize(n,1);
                c=n;
                for(int i=0;i<n;i++)
                parent[i]=i;
            }
            int find(int x){
                if(parent[x]!=x){
                    parent[x]=find(parent[x]);
                }
                return parent[x];
            }
            int required(int x,int y){
                int a=find(x),b=find(y);
                if(a==b)
                return 0;
                if(size[a]<size[b]){
                    swap(a,b);
                }
                parent[b]=a;
                size[a]+=size[b];
                c--;
                return 1;
            }
            int connected(){
                return c==1?1:0;
            }
        };
        int e=0;
        Union alice(n),bob(n);
        for(auto num:edges){
            if(num[0]==3){
                if(alice.required(num[1]-1,num[2]-1)|bob.required(num[1]-1,num[2]-1))
                e++;
            }
        }
        for(auto num:edges){
            if(num[0]==1){
                if(alice.required(num[1]-1,num[2]-1))
                e++;
            }
            if(num[0]==2){
                if(bob.required(num[1]-1,num[2]-1))
                e++;
            }
        }
        if(alice.connected()&&bob.connected())
        return edges.size()-e;
        return -1;
    }
};