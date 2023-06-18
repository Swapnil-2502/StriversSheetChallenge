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

bool detectCycle(Node *head)
{
	//Better (Using Hashing)
    unordered_set<Node* > st;
    Node* temp = head;

    while(temp != NULL){
        if(st.find(temp) != st.end()) return true;

        st.insert(temp);
        temp = temp->next;
    }
    return false;
    //TC = O(len(list))
    //SC = O(len(list))

    //Optimal
    Node* fast = head;
    Node* slow = head;

    while(fast->next !=NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) return true;
    }
    return false;
    //TC = O(N);
    //SC = O(1);
}