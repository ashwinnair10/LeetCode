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
    unordered_map<long,int> map;
    int c=0;
    int count(TreeNode* root,long sum,int target){
        if(!root)
        return 0;
        sum+=root->val;
        int c=map[sum-target];
        map[sum]++;
        c+=count(root->left,sum,target);
        c+=count(root->right,sum,target);
        map[sum]--;
        return c;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map[0]=1;
        return count(root,0,targetSum);
    }
};