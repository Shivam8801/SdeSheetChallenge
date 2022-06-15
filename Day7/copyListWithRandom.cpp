#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head == NULL) return NULL;
            
    LinkedListNode<int>* temp = head;
    LinkedListNode<int>* front;

    while(temp != NULL)
    {
        front = temp->next;
        LinkedListNode<int>* n = new LinkedListNode<int>(temp->data);
        temp->next = n;
        n->next = front;
        temp = front;
    }

    LinkedListNode<int>* iter = head;

    while(iter != NULL)
    {
        iter->next->random = (iter->random != NULL) ? iter->random->next : NULL;
        iter = iter->next->next;
    }

    LinkedListNode<int>* newhead = new LinkedListNode<int>(0);
    LinkedListNode<int>* dptr = newhead;
    iter = head;

    while(iter != NULL)
    {
        front = iter->next->next;
        dptr->next = iter->next;
        iter->next = front;
        dptr = dptr->next;
        iter = iter->next;
    }
    return newhead->next;
 
}
