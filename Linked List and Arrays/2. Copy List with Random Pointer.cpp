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
    //Brute (Hashing)
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*> mp;
    LinkedListNode<int>* temp = head;

    while(temp != NULL){
        LinkedListNode<int>* newNode = new LinkedListNode<int>(temp->data);
        mp[temp]=newNode;
        temp = temp->next;
    }

    LinkedListNode<int>* t = head;

    while(t != NULL){
        LinkedListNode<int>* node = mp[t];
        node->next = (t->next != NULL)? mp[t->next]:NULL;
        node->random = (t->random != NULL)? mp[t->random]:NULL;
        t=t->next;
    }
    return mp[head];
    //TC = O(2*N);
    //SC = O(N);

    //Optimised
    LinkedListNode<int>* temp=head;

    //Step1
    while(temp != NULL){
        LinkedListNode<int>* newNode = new LinkedListNode<int>(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    //Step2
    LinkedListNode<int>* itr=head;

    while(itr != NULL){
        if(itr->random != NULL) 
            itr->next->random = itr->random->next;

        itr = itr->next->next;
    }

    itr = head;
    LinkedListNode<int>* dummy = new LinkedListNode<int>(0);
    temp = dummy;
    LinkedListNode<int>* fast;

    while(itr != NULL){
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }

    return dummy->next;
    //TC = O(N + N + N);
    //SC = O(1);
}
