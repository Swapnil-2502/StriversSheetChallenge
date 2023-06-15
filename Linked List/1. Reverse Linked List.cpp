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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //iterative
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* nextp;

    while(curr){
        nextp = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextp;
    }

    head = prev;
    return head;
    //TC = O(N);
    //SC = O(1); only using three pointers;

    //Recursive
    
    //base case
    if(head==NULL || head->next==NULL) return head;

    LinkedListNode<int>* nnode = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
    //TC = O(N); Traversing once
    //SC =O(1); ignoring recursion stack space

    
}