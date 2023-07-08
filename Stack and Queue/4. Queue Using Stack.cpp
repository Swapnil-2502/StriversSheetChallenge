#include <bits/stdc++.h>

class Queue {
    stack<int> s1,s2;
    int size;
    
    public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        //Step1: Push all val from s1 to s2;
        while(!s1.empty()){
            int element = s1.top();
            s1.pop();
            s2.push(element);
        }

        //Step2: push val to s1;
        s1.push(val);

        //Step3: Push all elements of s2 back to s1;
        while(!s2.empty()){
            int element = s2.top();
            s2.pop();
            s1.push(element);
        }

        //Dont forget to increase the size;
        size++;
    }

    int deQueue() {
        if(size!=0){
            int element = s1.top();
            s1.pop();
            size--;
            return element;
        }
        else{
            return -1;
        }
    }

    int peek() {
        if(size!=0){
            int val = s1.top();
            return val;
        }
        else return -1;
    }

    bool isEmpty() {
        return (size == 0)?1:0;
    }
};