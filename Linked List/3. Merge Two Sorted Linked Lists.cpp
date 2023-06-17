#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
   //Brute using Dummy Nodes
   Node<int>* dummy = new Node<int>(0);
   Node<int>* headDummy = dummy;

   while(1){

       if(first == NULL){
           headDummy->next = second;
           break;
        }
        if(second == NULL){
           headDummy->next = first;
           break;
        }

        if(first->data <= second->data){
            headDummy->next = first;
            first = first->next;
        }
        else{
            headDummy->next = second;
            second = second->next;
        }

        headDummy = headDummy->next;

   }

   return dummy->next;
    //TC = O(N+M);
    //SC = O(N+M);

    //Optimal without using extra space

    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data > second->data) swap(first,second);

    Node<int>* res = first;

    while(first != NULL && second != NULL){

        Node<int>* temp = NULL;

        while(first != NULL && first->data <= second->data){
            temp = first;
            first = first->next;
        }

        temp->next = second;
        swap(first,second);

    }
    return res;
    //TC = O(N+M);
    //SC = O(1);


}
