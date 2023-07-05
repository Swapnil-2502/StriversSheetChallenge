#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> MaxHeap;
    priority_queue<int,vector<int>,greater<int>> MinHeap;

    for(int i=0;i<n;i++){

        if(MaxHeap.empty() || MaxHeap.top() >= arr[i]) MaxHeap.push(arr[i]);
        else MinHeap.push(arr[i]);

        if(MaxHeap.size() > MinHeap.size()+1){
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }
        else if(MinHeap.size()>MaxHeap.size()){
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }

        if(MinHeap.size()<MaxHeap.size()) cout<<MaxHeap.top()<<" ";
        else cout<<(MinHeap.top()+MaxHeap.top())/2<<" ";
    }
    //TC = O(nlogn);
    //SC = O(n);
}