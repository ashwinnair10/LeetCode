class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        unordered_map<int,TreeNode*> map;
        unordered_map<TreeNode*,int> root;
        for(auto i :a){
            auto k=map.find(i[0]);
            auto j=map.find(i[1]);
            TreeNode* m;
            TreeNode* n;
            if(k!=map.end()&&j!=map.end()){
                m=map[i[0]];
                n=map[i[1]];
            }
            else if(k!=map.end()){
                m=map[i[0]];
                n=new TreeNode(i[1]);
                map.insert(make_pair(i[1],n));
            }
            else if(j!=map.end()){
                n=map[i[1]];
                m=new TreeNode(i[0]);
                map.insert(make_pair(i[0],m));
            }
            else{
                n=new TreeNode(i[1]);
                m=new TreeNode(i[0]);
                map.insert(make_pair(i[0],m));
                map.insert(make_pair(i[1],n));
            }
            if(i[2]){
                m->left=n;
            }
            else{
                m->right=n;
            }
            if(root[m]!=1)
            root[m]=0;
            root[n]=1;
        }
        for(auto i:root)
        if(i.second==0)
        return i.first;
        return nullptr;
    }
};