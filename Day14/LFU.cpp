#include<map>

struct node
{
    int key, val, cnt;
    node* prev;
    node* next;
    node(int _key, int _val)
    {
        key = _key;
        val = _val;
        cnt = 1;
    }
};


struct list
{
    int size;
    node *head;
    node *tail;

    list()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
        size++;
    }

    void removeNode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }

};


class LFUCache
{
public: 

    map<int, list*> freqlistMap;
    map<int, node*> keyNode;
    int maxsizeCache;
    int minFreq;
    int curSize;
    LFUCache(int capacity)
    {
        // Write your code here.
        maxsizeCache = capacity; 
        minFreq = 0;
        curSize = 0;
        
    }
    
    void updatefreqlistMap(node* n)
    {
        keyNode.erase(n->key);
        freqlistMap[n->cnt]->removeNode(n);
        if(n->cnt == minFreq && freqlistMap[n->cnt]->size == 0)
            minFreq++;
        
        list* nextHigherFreqList = new list();
        if(freqlistMap.find(n->cnt + 1) != freqlistMap.end()) // that count is present
        {
            nextHigherFreqList = freqlistMap[n->cnt + 1];
        }
        n->cnt += 1;
        nextHigherFreqList->addFront(n);
        freqlistMap[n->cnt] = nextHigherFreqList;
        keyNode[n->key] = n;
    }

    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key) != keyNode.end())
        {
            node* n = keyNode[key];
            int value = n->val;
            updatefreqlistMap(n);
            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxsizeCache == 0)
            return;
        if(keyNode.find(key) != keyNode.end())
        {
            node* exVal = keyNode[key];
            exVal->val = value;
            updatefreqlistMap(exVal);
        }
        else
        {
            if(curSize == maxsizeCache)
            {
                list* l = freqlistMap[minFreq];
                keyNode.erase(l->tail->prev->key);
                freqlistMap[minFreq]->removeNode(l->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            list* listfreq = new list();
            if(freqlistMap.find(minFreq) != freqlistMap.end())
            {
                listfreq = freqlistMap[minFreq];
            }
            node* n = new node(key, value);
            listfreq->addFront(n);
            keyNode[key] = n;
            freqlistMap[minFreq] = listfreq;   
        }
    }
};
