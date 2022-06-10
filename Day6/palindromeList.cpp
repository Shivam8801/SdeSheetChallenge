#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverse(LinkedListNode<int> *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    LinkedListNode<int>* newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}


bool isPalindrome(LinkedListNode<int> *head) {  
    if(head == NULL || head->next == NULL) return true;
    
    LinkedListNode<int>* initial = head, *slow = head, *fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = reverse(slow->next);
    slow = slow->next;
    
    while(slow != NULL)
    {
        if(slow->data != initial->data)
            return false;
        
        slow = slow->next;
        initial = initial->next;
    }
    return true;  
}
