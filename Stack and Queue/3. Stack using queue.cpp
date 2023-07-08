#include <bits/stdc++.h> 
class Stack {
	queue<int> q1,q2;
    int size;

   public:
    Stack() {
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size == 0)?1:0;
    }

    void push(int element) {
        //Step1: Push elements to q2 first;
        q2.push(element);

        //Step2: Push all elements of q1 to q2;
        while(!q1.empty()){
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }

        //Step3: Swap q1 and q2
        swap(q1,q2);

        //Dont forget to update the size;
        size++;

    }

    int pop() {
        if(!q1.empty()){
            int val = q1.front();
            q1.pop();

            //Dont forget to update the size;
            size--;

            return val;
        }
        else return -1;
    }

    int top() {
        if(!q1.empty()){
            return q1.front();
        }
        else return -1;
    }
};