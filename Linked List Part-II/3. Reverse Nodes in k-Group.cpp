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

int findLengthOfList(Node* head){
	int count = 0;
	Node* temp = head;
	
	while(temp != NULL){
		temp=temp->next;
		count++;
	}

	return count;
}

Node* reverse(Node* head){
	Node* curr = head, *nxt, *prev=NULL;

	while(curr){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}

	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){

	// if(head == NULL) return head;

	int length = findLengthOfList(head);

	Node* dummy = new Node(0);
	dummy->next = head;

	Node* prev = dummy,*curr,*nxt;

	for(int i=0;i<n;i++){

		if(length==0) break;

		if(b[i] <= length){
			curr = prev->next;
			nxt = curr->next;

			if(b[i] == 0) continue;

			for(int j=0;j<b[i]-1;j++){
				curr->next = nxt->next;
				nxt->next = prev->next;
				prev->next = nxt;
				nxt = curr->next;
			}

			length -= b[i];
			prev = curr;
		}
		else if(b[i] > length){
			prev->next = reverse(prev->next);
			length = 0;
		}
	}
	
	return dummy->next;
	
}