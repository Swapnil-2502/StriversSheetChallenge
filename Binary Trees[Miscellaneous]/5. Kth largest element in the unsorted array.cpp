#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	//Using heaps
	priority_queue<int,vector<int>,greater<int>> pq;

	for(int i=0;i<size;i++){
		pq.push(arr[i]);

		if(pq.size()>K) pq.pop();
	}
	return pq.top();
	//Tc = O(nlogk);
	//Sc = O(k);
	
}