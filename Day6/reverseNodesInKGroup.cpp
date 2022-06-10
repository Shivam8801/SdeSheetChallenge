#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head == NULL) return NULL;

    Node* dummy = new Node(0);
    dummy->next = head;
    int count = 0;
    
    Node *curr = dummy, *pre = dummy, *nex = dummy;
    
    while(curr->next != NULL)
    {
        curr = curr->next;
        count++;
    }
    
    int j = 0;
    while(count > 0 && j < n)
    {
        curr = pre->next;
        nex = curr->next;
        int k = min(count, b[j]);
        for(int i = 1; i < k; i++)
        {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        if(k > 0) pre = curr;
        count -= k;
        j++;
    }
    return dummy->next;
        
}
