class Solution {
public:
    void levelTraversal(Node* root,vector<vector<Node*>>& level,int l){
        if(root==nullptr)
        return;
        if(l==level.size())
        level.push_back({});
        level[l].push_back(root);
        levelTraversal(root->left,level,l+1);
        levelTraversal(root->right,level,l+1);
    }
    Node* connect(Node* root) {
        if(root==nullptr)
        return root;
        vector<vector<Node*>> level;
        levelTraversal(root,level,0);
        for(auto i:level){
            for(int j=0;j<i.size()-1;j++){
                i[j]->next=i[j+1];
            }
        }
        return root;
    }
};