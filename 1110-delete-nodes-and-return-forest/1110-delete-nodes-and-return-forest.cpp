/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int operate(unordered_set<TreeNode*>& set,TreeNode* parent,TreeNode* root,int k){
        if(root==nullptr)
        return 0;
        if(root->val==k&&parent==root){
            if(root->left!=nullptr){
                set.insert(root->left);
                root->left=nullptr;
            }
            if(root->right!=nullptr){
                set.insert(root->right);
                root->right=nullptr;
            }
            set.erase(root);
            return 1;
        }
        if(root->val==k){
            if(root->left!=nullptr){
                set.insert(root->left);
                root->left=nullptr;
            }
            if(root->right!=nullptr){
                set.insert(root->right);
                root->right=nullptr;
            }
            if(parent->left==root)
            parent->left=nullptr;
            else
            parent->right=nullptr;
            return 1;
        }
        return operate(set,root,root->left,k)||operate(set,root,root->right,k);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<TreeNode*> set;
        set.insert(root);
        for(auto k:to_delete){
            for(auto i:set){
                if(operate(set,i,i,k))
                break;
            }
        }
        vector<TreeNode*> ans;
        for(auto i:set)
        ans.push_back(i);
        return ans;
    }
};