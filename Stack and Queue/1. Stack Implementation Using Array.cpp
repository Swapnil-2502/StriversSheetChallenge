#include <bits/stdc++.h> 
// Stack class.
class Stack {

private:
    int* arr;
    int topp;
    int size;
    
public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        topp = 0;
        size = capacity;
    }

    void push(int num) {
        if(topp != size){
            arr[topp] = num;
            topp++;
        }
    }

    int pop() {
        if(topp != 0){
            topp--;
            return arr[topp];
        }
        return -1;
    }
    
    int top() {
        return (topp!=0)?(arr[topp-1]):-1;
    }
    
    int isEmpty() {
        return (topp==0)?1:0;
    }
    
    int isFull() {
        return (topp==size);
    }
    
    //TC = O(N);
    //SC = O(N);
};