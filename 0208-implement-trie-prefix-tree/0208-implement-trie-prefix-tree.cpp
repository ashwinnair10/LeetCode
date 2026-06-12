class Trie {
public:
    struct Node{
        int end;
        vector<Node*> children;
        Node(){
            end=0;
            children.resize(26,nullptr);
        }
    };
    vector<Node*> root;
    Trie() {
        root.resize(26,nullptr);
    }
    
    void insert(string word) {
        if(!root[word[0]-'a']){
            root[word[0]-'a']=new Node();
        }
        Node* curr=root[word[0]-'a'];
        for(int i=1;i<word.length();i++){
            if(!curr->children[word[i]-'a']){
                curr->children[word[i]-'a']=new Node();
            }
            curr=curr->children[word[i]-'a'];
        }
        curr->end=1;
    }
    
    bool search(string word){
        if(!root[word[0]-'a']){
            return false;
        }
        Node* curr=root[word[0]-'a'];
        for(int i=1;i<word.length();i++){
            if(!curr->children[word[i]-'a']){
                return false;
            }
            curr=curr->children[word[i]-'a'];
        }
        return curr->end?true:false;
    }
    
    bool startsWith(string word) {
        if(!root[word[0]-'a']){
            return false;
        }
        Node* curr=root[word[0]-'a'];
        for(int i=1;i<word.length();i++){
            if(!curr->children[word[i]-'a']){
                return false;
            }
            curr=curr->children[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */