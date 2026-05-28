class Solution {
    struct Node{
        int val;
        Node* children[26];
        Node(int x): val(x) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void clearTrie(Node* root) {
        if (!root) return;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                clearTrie(root->children[i]);
            }
        }
        delete root;
    }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        int minimum=INT_MAX,index=0;
        Node* root[26];
        for (int i = 0; i < 26; i++) {
            root[i] = nullptr;
        }
        for(int i=0;i<wordsContainer.size();i++){
            string s=wordsContainer[i];
            if(s.length()<minimum){
                minimum=s.length();
                index=i;
            }
            reverse(s.begin(),s.end());
            if(!root[s[0]-'a']){
                root[s[0]-'a']=new Node(i);
            }
            else{
                if(wordsContainer[root[s[0]-'a']->val].length()>wordsContainer[i].length()){
                    root[s[0]-'a']->val=i;
                }
            }
            Node* start=root[s[0]-'a'];
            for(int j=1;j<s.length();j++){
                if(!start->children[s[j]-'a']){
                    start->children[s[j]-'a']=new Node(i);
                }
                else{
                    if(wordsContainer[start->children[s[j]-'a']->val].length()>wordsContainer[i].length()){
                        start->children[s[j]-'a']->val=i;
                    }
                }
                start=start->children[s[j]-'a'];
            }
        }

        for(int i=0;i<wordsQuery.size();i++){
            string s=wordsQuery[i];
            reverse(s.begin(),s.end());
            int a=index;
            Node* start=root[s[0]-'a'];
            int j=0;
            while(start&&j<s.length()){
                a=start->val;
                j++;
                if(j<s.length())
                start=start->children[s[j]-'a'];
            }
            ans.push_back(a);
        }

        for (int i = 0; i < 26; i++) {
            if (root[i]) {
                clearTrie(root[i]);
            }
        }

        return ans;
    }
};