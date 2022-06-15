#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
    
    if(head->next == NULL || k == 0) return head;
    
    int len = 1;
    Node* temp = head;
    
    while(temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    temp->next = head;
    
    k = k % len;
    k = len - k;
    
    while(k > 0)
    {
        temp = temp->next;
        k--;
    }
    
    head = temp->next;
    temp->next = NULL;
    
    return head; 
    
}
