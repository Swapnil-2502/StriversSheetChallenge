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

Node* removeKthNode(Node* head, int K)
{

    //BRUTE
    if(head == NULL) return head;

    int countNodes = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        countNodes++;
    }

    //Case1: First Node
    if(K==countNodes) return head->next;

    //Case2: Last Node
    temp = head;
    if(K==1){
        while(temp->next->next != NULL){
            temp = temp->next;
            
        }
        temp->next = NULL;
        return head;
    }
  
    //Case3: Any Node between
    temp = head;
    for(int i=0;i<countNodes-K-1;i++){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;

    delete del;

    return head;
    //TC = O(2*N);
    //SC = O(1);

    //Optimal (Using Two Pointers)
    Node* start = new Node();
    start->next = head;

    Node* slow = start;
    Node* fast = start;

    for(int i=1;i<=K;i++){
        fast = fast->next;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
    //TC = O(N);
    //SC = O(1);


}
