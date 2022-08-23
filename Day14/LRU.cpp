#include <unordered_map>

class LRUCache
{
public:
    class node
    {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }         
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> m;
    
      
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }
    
    void deleteNode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        // Write your code here
        if(m.find(key) != m.end())
        {
            node* n = m[key];
            int res = n->val;
            m.erase(key);
            deleteNode(n);
            addNode(n);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        node* n = new node(key, value);
        if(m.find(key) != m.end())
        {
            node* exVal = m[key];
            m.erase(key);
            deleteNode(exVal);
        }
        if(m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(n);
        m[key] = head->next;    
    }
};
