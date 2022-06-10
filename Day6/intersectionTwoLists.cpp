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

int findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead == NULL && secondHead == NULL) return NULL;
    
    Node* ptr1 = firstHead;
    Node* ptr2 = secondHead;
        
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1 == NULL ? secondHead : ptr1->next;
        ptr2 = ptr2 == NULL ? firstHead : ptr2->next;

    }
    return ptr1 == NULL ? -1 : ptr1->data;       
}
