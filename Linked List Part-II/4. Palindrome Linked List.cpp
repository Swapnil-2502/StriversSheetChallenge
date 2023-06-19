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

LinkedListNode<int> *reverse(LinkedListNode<int> * head){

    LinkedListNode<int>* curr = head,*prev = NULL,*nxt;

    while(curr){
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;

    }

    return prev;
    
}

bool isPalindrome(LinkedListNode<int> *head) {
    //Base case kind
    if(head == NULL || head->next == NULL) return true;
    
    //Brute (using extra space)
    vector<int>arr;
    LinkedListNode<int>* temp = head;

    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    for(int i=0;i<arr.size()/2;i++){
        if(arr[i] != arr[arr.size()-i-1]) return false;
    }
    return true;
    //TC = O(N);
    //SC = O(N);

    //Optimised

    //Find middle element
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    //Now slow points to middle element 
    //Now reverse the remaining list
    slow->next = reverse(slow->next);

    slow = slow->next;
    LinkedListNode<int>* dummy = head;

    while(slow){
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
    //TC = O(N/2) + O(N/2) + O(N/2);
    //SC = O(1);
}