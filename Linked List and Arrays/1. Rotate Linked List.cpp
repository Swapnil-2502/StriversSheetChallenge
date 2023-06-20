/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     
     //Brute
     for(int i=0;i<k;i++){
          Node* temp = head;

          while(temp->next->next != NULL) temp = temp->next;

          Node* end = temp->next;
          temp->next = NULL;
          end->next = head;
          head = end;
     }

     return head;
     //TC = O(N*K);
     //SC = O(1);

     //Optimal
     if(head == NULL || head->next == NULL || k==0) return head;
     
     int length = 1;
     Node* temp = head;

     while(temp->next != NULL){
          length++;
          temp = temp->next;
     }

     temp->next = head;

     k = k%length;
     int end = length-k;


     while(end--) temp = temp->next;

     head = temp->next;
     temp->next = NULL;

     return head;
     //TC = O(length of list) + O(length of list - k%length);
     //SC = O(1);
}