#include <bits/stdc++.h> 
void insertSorted(stack<int>&s,int num){
    // Base Case :
    if(s.empty() || (s.top() < num)){
        s.push(num);
        return;
    }
 
    int n=s.top();
    s.pop();
 
    insertSorted(s,num);
 
    s.push(n);
}
 
void sortStack(stack<int> &stack)
{
    // Base case :
    if(stack.empty()){
        return;
    }
 
    int num=stack.top();
    stack.pop();
 
    sortStack(stack);
 
    insertSorted(stack,num);
}