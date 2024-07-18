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
    vector<string> v;
    int dist(string a,string b){
        int i=0,j=0;
        while(i<=a.size()&&j<=b.size()&&a[i]==b[j]){
            i++;
            j++;
        }
        cout<<"dist "<<a<<' '<<b<<" : "<<(a.size()-i)+(b.size()-j)<<'\n';
        return (a.size()-i)+(b.size()-j);
    }
    void inorder(TreeNode* root,string path){
        if(root!=nullptr){
            inorder(root->left,path+'L');
            if(root->left==nullptr&&root->right==nullptr){
                v.push_back(path);
            }
            inorder(root->right,path+'R');
        }
        return;
    }
    int countPairs(TreeNode* root, int distance) {
        inorder(root,"");
        for(auto i:v)
        cout<<i<<'\n';
        int c=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(dist(v[i],v[j])<=distance)
                c++;
            }
        }
        return c;
    }
};