/*
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
*/

Node *findMiddle(Node *head) {

    //BRUTE
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;    
    }
    temp = head;

    for(int i=0;i<count/2;i++){
        temp = temp->next;
    }
    return temp;
    //TC = O(N + N/2);
    //SC = O(1);

    //Efficient
    if(head == NULL || head->next == NULL) return head;
    
    Node* fast = head;
    Node* slow = head;

    while(fast !=NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    //TC = O(N);
    //SC = O(1);
}

