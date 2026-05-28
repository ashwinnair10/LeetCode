class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode* > q;
        int sum=0,level=1,m=INT_MIN,ml=-1;
        TreeNode* x=new TreeNode(INT_MAX);
        if(root==nullptr)
        return 0;
        q.push(root);
        q.push(x);
        while(!q.empty()){
            TreeNode* curr=q.front();
            sum+=curr->val;
            q.pop();
            TreeNode* check=q.front();
            if(check==x){
                if(sum>m){
                    m=sum;
                    ml=level;
                }
                sum=0;
                level++;
                q.pop();
            }
            if(curr->left!=nullptr)
            q.push(curr->left);
            if(curr->right!=nullptr)
            q.push(curr->right);
            if(check==x)
            q.push(x);
        }
        return ml;
    }
};