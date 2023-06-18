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

int findLength(Node *head){
    int count = 0;

    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    return count;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{   

    //Optimal
    Node* d1 = firstHead;
    Node* d2 = secondHead;

    while(d1 != d2){

        d1 = d1==NULL? firstHead: d1->next;
        d2 = d2==NULL? secondHead: d2->next;
    }

    return d1;
    //TC = O(2 * max(list1,list2));
    //SC = O(1);

    //Better
    int len1 = findLength(firstHead);
    int len2 = findLength(secondHead);

    int difference = abs(len1-len2);

    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    if(len1 > len2){
        for(int i=1;i<=difference;i++){
            temp1 = temp1->next;
        }
    }
    
    if(len1 < len2){
        for(int i=1;i<=difference;i++){
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2) return temp1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return NULL;
    //TC = O(max(lis1,list2) to find length) + O(abs(list1-list2)) +O(min(list1,list2) to find intersection) +
    //SC = O(1); 
}