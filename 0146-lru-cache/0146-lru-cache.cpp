class LRUCache {
public:
    struct Node {
        int key, val;
        Node* next;
        Node* prev;
    };

    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int cap;

    LRUCache(int capacity) {
        head = new Node();
        tail = new Node(); 
        head->next = tail;
        tail->prev = head;
        cap=capacity;
    }

    void delNode(Node* temp) {
        Node* pre = temp->prev;
        Node* nex = temp->next;
        pre->next = nex;
        nex->prev = pre;
    }
    void inshead(Node* temp) {
        Node* curr = head->next;
        head->next = temp;
        temp->prev = head; 
        temp->next = curr;
        curr->prev = temp;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; 
        }
        Node* temp = mp[key];
        delNode(temp);
        inshead(temp);
        return temp->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value; 
            delNode(node); 
            inshead(node);
        } else { 
            if (mp.size() == cap) { 
                Node* temp = tail->prev;
                delNode(temp);     
                mp.erase(temp->key);
                delete temp;        
            }
            Node* node = new Node();
            node->key=key;
            node->val=value;
            mp[key] = node;
            inshead(node); 
        }
    }
};