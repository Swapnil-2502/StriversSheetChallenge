/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    //Better (Hashing)
    unordered_map<Node*,int> mp;

    Node* temp = head;
    int i=0;

    while(temp){
        if(mp.find(temp) != mp.end()){
            return temp;
        }

        mp[temp]++;
        temp = temp->next;
    }
    return temp;
    //TC = O(N);
    //SC = O(N);

    //Optimised
    Node* fast = head;
    Node* slow = head;
    Node* entry = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
    //TC = O(N);
    //SC = O(1);
}